import pygame,sys
import pygame.freetype
from pygame.locals import *
import math
import serial

listColor=[]
listColor2=[]
index = 0
distance = 0.0
listIndex = []
listDistance = []
for i in range(40):
    ab = 250-i*8
    if ab < 0:
        ab = 0
    listColor.append((31,ab,31))
    listColor2.append((ab,10,10))
    # math.
for i in range(200):
    listIndex.append(0)
    listDistance.append(200)

serialPort = input('输入COM口：')
serialBaund = 9600
ser = serial.Serial(serialPort,serialBaund,timeout=0.5)

pygame.init()
size = width,height = 800,500
screen = pygame.display.set_mode(size)
pygame.display.set_caption('雷达检测')
