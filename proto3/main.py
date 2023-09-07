import serial # pySerial
from time import sleep
import pygame # Conexão com a placa Zero Delay

laires = serial.Serial("/dev/ttyUSBX", 115200) # ou "COMX", sendo X dependendo da porta

pygame.joystick.init()
joystick = pygame.joystick.Joystick(0)
joystick.init()

# Para Windows:
# joysticks = [pygame.joystick.Joystick(x) for x in range(pygame.joystick.get_count())]
# if len(joysticks) == 0:
#     raise Exception("Placa Zero Delay não conectada!")

pygame.init()
while True:
    for event in pygame.event.get():
        if event.type == pygame.JOYBUTTONDOWN:
            if event.dict['button'] == 0:
                print('gira')
                laires.write(b'gira')
            else:
                print(event.dict['button'])