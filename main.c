#include "raylib.h"
#include "player.h"
#include "tilemap.h"



int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Animations");

    Texture2D tileset = LoadTexture("assets/TileMapTest.png");

    if (!LoadMapFromFile("map.txt")) {
        CloseWindow();
        return 1;
    }

    Player player;
    InitPlayer(&player);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdatePlayer(&player);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawTilemap(tileset);
        DrawPlayer(&player);      

        
        EndDrawing();
    }

    UnloadPlayer(&player);
    CloseWindow();

    return 0;
}