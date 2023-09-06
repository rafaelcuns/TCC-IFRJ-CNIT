import serial # pySerial
from time import sleep

laires = serial.Serial("/dev/ttyUSBX", 115200) # ou "COMX", sendo X dependendo da porta
sleep(1)
laires.write(b'gira')