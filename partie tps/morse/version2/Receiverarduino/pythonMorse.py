import time
import serial

'''
. vaut 1 u de temps
- vaut 3 u de teps
l'espace entre les symbols (. et -) de la meme lettre est de 1 u de temps
l'espace entre les lettre vaut 3u
lespace entre les mots vaut 7u
'''

uniteDeTemps=0.5 #0.5s

CODE = {'A': '.-',     'B': '-...',   'C': '-.-.', 
        'D': '-..',    'E': '.',      'F': '..-.',
        'G': '--.',    'H': '....',   'I': '..',
        'J': '.---',   'K': '-.-',    'L': '.-..',
        'M': '--',     'N': '-.',     'O': '---',
        'P': '.--.',   'Q': '--.-',   'R': '.-.',
     	'S': '...',    'T': '-',      'U': '..-',
        'V': '...-',   'W': '.--',    'X': '-..-',
        'Y': '-.--',   'Z': '--..',   ' ': ' ',
        
        '0': '-----',  '1': '.----',  '2': '..---',
        '3': '...--',  '4': '....-',  '5': '.....',
        '6': '-....',  '7': '--...',  '8': '---..',
        '9': '----.' 
        }


arduino= serial.Serial('COM11',9600, timeout=.1)
while 1:
	msg = input('MESSAGE: ')
	morsecode=""
	for char in msg:
		morsecode+=	(CODE[char.upper()])+","

	print(morsecode)


	for char in morsecode:
		if char==".":
			arduino.write('1'.encode())
			time.sleep(uniteDeTemps)
			arduino.write('0'.encode())
			time.sleep(uniteDeTemps)
		elif char=="-":
			arduino.write('1'.encode())
			time.sleep(uniteDeTemps*3)
			arduino.write('0'.encode())
			time.sleep(uniteDeTemps)
		elif char==",":
			time.sleep(uniteDeTemps*3)
		elif char==" ":
			time.sleep(uniteDeTemps*7)

