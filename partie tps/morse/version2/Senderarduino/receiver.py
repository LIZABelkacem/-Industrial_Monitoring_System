import keyboard
import time
import serial
laststate=0
arduino= serial.Serial('COM11',9600, timeout=.1)
time.sleep(1)
while True:
	data = arduino.readline()[:-2] #the last bit gets rid of the new-line chars
	if data:
		print(data)