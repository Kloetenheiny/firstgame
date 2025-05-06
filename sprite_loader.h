#include "raylib.h"


#ifndef SPRITEL_H
#define SPRITEL_H

typedef struct SpriteAnim {
    Texture2D texture;
    Vector2 position;
    Rectangle frameRec;
    int currentFrame;
    int framesCounter;
    int framesSpeed;
    int maxFrames;
    float scale;
} SpriteAnim;


void InitSpriteAnim(SpriteAnim *sprite, const char *texturePath, int maxFrames, Vector2 position, int framesSpeed, float scale);
void UpdateSpriteAnim(SpriteAnim *sprite);
void DrawSpriteAnim(SpriteAnim *sprite);
void UnloadSpriteAnim(SpriteAnim *sprite);


#endif