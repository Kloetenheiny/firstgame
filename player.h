#include "raylib.h"
#include "sprite_loader.h"


#ifndef PLAYER_H
#define PLAYER_H

typedef enum Direction {
    DIR_DOWN = 0,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP,
    IDLE,
    ATTACK
} Direction;

typedef struct Player {
    SpriteAnim anims[5];
    Direction currentDir;
} Player;

void InitPlayer(Player *player);
void UpdatePlayer(Player *player);
void DrawPlayer(Player *player);
void UnloadPlayer(Player *player);


#endif