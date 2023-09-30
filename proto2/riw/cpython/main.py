from flask import Flask, Response, render_template
import numpy as np
import math
import serial
import cv2
from cvzone.HandTrackingModule import HandDetector
from cvzone.ClassificationModule import Classifier
from time import sleep

# laires = serial.Serial('COM6', 115200)

labels = ["Pedra", "Papel", "Tesoura"]
offset = 20
imgSize = 300
status = ""

conn = cv2.VideoCapture(0)
if not conn.isOpened():
    print("Não foi possível se conectar com a câmera!")
    exit()
conn.set(cv2.CAP_PROP_EXPOSURE, 0.5)
detector = HandDetector(maxHands=1)
classifier = Classifier("Model/keras_model.h5", "Model/labels.txt")

server = Flask("")

@server.route('/')
def handleRoot():
    return render_template("index.html")

@server.route('/camera')
def streamPython():
    def stream():
        global status
        while True:
            retorno, img = conn.read()
            img = cv2.flip(img, 1)

            imgOutput = img.copy()
            hands, img = detector.findHands(img)
            if hands:
                hand = hands[0]
                x, y, w, h = hand['bbox']

                imgWhite = np.ones((imgSize, imgSize, 3), np.uint8) * 255
                imgCrop = img[y - offset:y + h + offset, x - offset:x + w + offset]

                imgCropShape = imgCrop.shape

                aspectRatio = h / w

                if aspectRatio > 1:
                    k = imgSize / h
                    wCal = math.ceil(k * w)
                    imgResize = cv2.resize(imgCrop, (wCal, imgSize))
                    imgResizeShape = imgResize.shape
                    wGap = math.ceil((imgSize - wCal) / 2)
                    imgWhite[:, wGap:wCal + wGap] = imgResize
                    prediction, index = classifier.getPrediction(imgWhite, draw=False)
                    print(np.max(prediction), index) # Mostra o index da classe de maior probabilidade
                    if np.max(prediction) > 0.8:
                        status = labels[index] # Falta mostrar jogada do robo e resultado do jogo. Em uma unica string separados por virgula
                        # laires.write(b'' + labels[index])

                else:
                    k = imgSize / w
                    hCal = math.ceil(k * h)
                    imgResize = cv2.resize(imgCrop, (imgSize, hCal))
                    imgResizeShape = imgResize.shape
                    hGap = math.ceil((imgSize - hCal) / 2)
                    imgWhite[hGap:hCal + hGap, :] = imgResize
                    prediction, index = classifier.getPrediction(imgWhite, draw=False)
                    print(np.max(prediction), index) # Mostra o index da classe de maior probabilidade
                    if np.max(prediction) > 0.8:
                        status = labels[index] # Falta mostrar jogada do robo e resultado do jogo. Em uma unica string separados por virgula
                        # laires.write(b'' + labels[index])

            imgBytes = cv2.imencode('.jpg', imgOutput)[1].tobytes()

            yield(b'--frame\r\n' b'Content-Type: image/jpeg\r\n\r\n' + imgBytes + b'\r\n')
    return Response(stream(), mimetype='multipart/x-mixed-replace; boundary=frame')

@server.route("/<path>")
def comandoPath(path):
    print(path)
    # laires.write(b'' + path)
    sleep(2)
    return Response((yield(b'Recebido')), mimetype='text/html')

@server.route("/jogoStatus")
def status():
    return Response((yield(b'' + status.encode())), mimetype='text/html')


server.run(host='localhost', port=80)