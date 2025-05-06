#include "player.h"

void InitSpriteAnim(SpriteAnim *sprite, const char *texturePath, int maxFrames, Vector2 position, int framesSpeed, float scale) {
    sprite->texture = LoadTexture(texturePath);
    sprite->position = position;
    sprite->maxFrames = maxFrames;
    sprite->framesSpeed = framesSpeed;
    sprite->currentFrame = 0;
    sprite->framesCounter = 0;
    sprite->scale = scale;
    sprite->frameRec = (Rectangle){ 0.0f, 0.0f, (float)sprite->texture.width / maxFrames, (float)sprite->texture.height };
}

void UpdateSpriteAnim(SpriteAnim *sprite) {
    sprite->framesCounter++;
    if (sprite->framesCounter >= (60 / sprite->framesSpeed)) {
        sprite->framesCounter = 0;
        sprite->currentFrame++;
        if (sprite->currentFrame >= sprite->maxFrames) sprite->currentFrame = 0;
        sprite->frameRec.x = (float)sprite->currentFrame * sprite->frameRec.width;
    }
}

void DrawSpriteAnim(SpriteAnim *sprite) {
    Vector2 origin = { 0.0f, 0.0f };
    Rectangle destRec = {
        sprite->position.x,
        sprite->position.y,
        sprite->frameRec.width * sprite->scale,
        sprite->frameRec.height * sprite->scale
    };
    DrawTexturePro(sprite->texture, sprite->frameRec, destRec, origin, 0.0f, WHITE);
}

void UnloadSpriteAnim(SpriteAnim *sprite) {
    UnloadTexture(sprite->texture);
}

void InitPlayer(Player *player) {
    InitSpriteAnim(&player->anims[DIR_DOWN],  "assets/1 Characters/1/D_Walk.png", 6, (Vector2){ 400, 200 }, 6, 4.0f);
    InitSpriteAnim(&player->anims[DIR_LEFT],  "assets/1 Characters/1/S_Walk.png", 6, (Vector2){ 400, 200 }, 6, 4.0f);
    InitSpriteAnim(&player->anims[DIR_RIGHT], "assets/1 Characters/1/A_Walk.png", 6, (Vector2){ 400, 200 }, 6, 4.0f);
    InitSpriteAnim(&player->anims[DIR_UP],    "assets/1 Characters/1/U_Walk.png", 6, (Vector2){ 400, 200 }, 6, 4.0f);
    InitSpriteAnim(&player->anims[IDLE],      "assets/1 Characters/1/D_Idle.png", 4, (Vector2){ 400, 200 }, 6, 4.0f);
    InitSpriteAnim(&player->anims[ATTACK],    "assets/1 Characters/1/D_Idle.png", 4, (Vector2){ 400, 200 }, 6, 4.0f);


    player->currentDir = IDLE;
}

void UpdatePlayer(Player *player) {
    Vector2 move = { 0,0 };
    bool moving = false;


    if (IsKeyDown(KEY_W)) { move.y -= 100.0f; player->currentDir = DIR_UP; moving = true; }
    if (IsKeyDown(KEY_S)) { move.y += 100.0f; player->currentDir = DIR_DOWN; moving = true; }
    if (IsKeyDown(KEY_A)) { move.x -= 100.0f; player->currentDir = DIR_LEFT; moving = true; }
    if (IsKeyDown(KEY_D)) { move.x += 100.0f; player->currentDir = DIR_RIGHT; moving = true; }


    for (int i = 0; i < 5; i++) {
        player->anims[i].position.x += move.x * GetFrameTime();
        player->anims[i].position.y += move.y * GetFrameTime();
    }

    
    if(moving == false){
        player->currentDir = IDLE;
    }

    UpdateSpriteAnim(&player->anims[player->currentDir]);
}

void DrawPlayer(Player *player) {
    DrawSpriteAnim(&player->anims[player->currentDir]);
}

void UnloadPlayer(Player *player) {
    for (int i = 0; i < 4; i++) {
        UnloadSpriteAnim(&player->anims[i]);
    }
}