import serial # pySerial

laires = serial.Serial("/dev/ttyUSBX", 115200) # X depende da porta
laires.write(b'gira')
laires.close()