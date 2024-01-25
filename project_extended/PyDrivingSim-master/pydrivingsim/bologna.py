# Authors : Matteo Zumerle
# Date    : 21/01/2024
# License : MIT

import pygame
import random

# red then green no stop
#random.seed(10)
# stop with red
#random.seed(1)

from pydrivingsim import VirtualObject, World

class BolognaSprite(pygame.sprite.Sprite):
    def __init__(self, segnale_bologna):
        super().__init__()
        img = "imgs/bologna.png"
        self.image_fix = []
        sprite = pygame.image.load(img).convert_alpha()
        w, h = sprite.get_size()
        scale = (World().scaling_factor * 35) / w
        self.image_fix.append(pygame.transform.smoothscale(sprite, (int(w * scale), int(h * scale))))

        self.image = self.image_fix[0]
        self.rect = self.image_fix[0].get_rect()
        self.size = self.image_fix[0].get_size()
        self.segnale_bologna = segnale_bologna

    def update(self) -> None:
        self.rect.center = [
            (self.segnale_bologna.pos[0] - World().get_world_pos()[0]) * World().scaling_factor + World().screen_world_center[0],
            (World().get_world_pos()[1] - self.segnale_bologna.pos[1]) * World().scaling_factor + World().screen_world_center[1]
        ]
        self.image = self.image_fix[self.segnale_bologna.state]

class Bologna(VirtualObject):
    __metadata = {
        "dt": 0.1
    }
    def __init__( self ):
        super().__init__(self.__metadata["dt"])
        # Sprite
        self.bologna = BolognaSprite(self)
        self.group = pygame.sprite.Group()
        self.group.add(self.bologna)

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
        self.bologna.update()
        self.group.draw(World().screen)