# Authors : Matteo Zumerle
# Date    : 21/01/2024
# License : MIT

import pygame
import random

# red then green no stop
#random.seed(90)
# stop with red
#random.seed(1)

from pydrivingsim import VirtualObject, World

class SegnaleSprite(pygame.sprite.Sprite):
    def __init__(self, segnale, vel):
        super().__init__()
        
        if vel == 10:
            img = "imgs/10.png"

        elif vel == 20:
            img = "imgs/20.png"

        elif vel == 30:
            img = "imgs/30.png"

        elif vel == 50:
            img = "imgs/50.png"

        elif vel == 60:
            img = "imgs/60.png"

        else:
            img = "imgs/90.png"
        
        self.image_fix = []
        sprite = pygame.image.load(img).convert_alpha()
        w, h = sprite.get_size()
        scale = (World().scaling_factor * 5) / w
        self.image_fix.append(pygame.transform.smoothscale(sprite, (int(w * scale), int(h * scale))))

        self.image = self.image_fix[0]
        self.rect = self.image_fix[0].get_rect()
        self.size = self.image_fix[0].get_size()
        self.segnale = segnale

    def update(self) -> None:
        self.rect.center = [
            (self.segnale.pos[0] - World().get_world_pos()[0]) * World().scaling_factor + World().screen_world_center[0],
            (World().get_world_pos()[1] - self.segnale.pos[1]) * World().scaling_factor + World().screen_world_center[1]
        ]
        self.image = self.image_fix[self.segnale.state]

class Signal(VirtualObject):
    __metadata = {
        "dt": 0.1
    }
    def __init__( self, vel ):
        super().__init__(self.__metadata["dt"])
        # Sprite
        self.signal = SegnaleSprite(self, vel)
        self.group = pygame.sprite.Group()
        self.group.add(self.signal)
        self.vel = vel

        self.state = 0
        self.lenght = 0.3
        self.width = 0.3
        self.pos = (0,0)
        self.reset()

    def set_pos(self, point: tuple):
        self.pos = point

    def reset(self):
        self.state = 0

    def render( self ):
        self.signal.update()
        self.group.draw(World().screen)