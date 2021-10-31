import serial
import time

distance = 3
key1 = 6
key2 = 3

serialBaud = 9600
ser = serial.Serial('COM15',serialBaud,timeout=0.5)

while True:
    distance = int(input(print('请输入距离：')))
    if distance < 5:
        data = bytes(key1)
        ser.write("5555".encode('utf-8'))
        time.sleep(1)
    else:
        data = bytes.fromhex(key2)
        ser.write(key2)
