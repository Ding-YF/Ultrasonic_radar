import pygame
pygame.init()
running = True

pygame.display.set_mode((400,800))

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

