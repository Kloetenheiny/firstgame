#ifndef TILEMAP_H
#define TILEMAP_H

#include "raylib.h"
#include <stdbool.h>

#define TILE_SIZE 32
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAP_WIDTH (SCREEN_WIDTH / TILE_SIZE)
#define MAP_HEIGHT (SCREEN_HEIGHT / TILE_SIZE)

extern int tilemap[MAP_HEIGHT][MAP_WIDTH];

bool LoadMapFromFile(const char *filename);
void DrawTilemap(Texture2D tileset);

#endif // TILEMAP_H