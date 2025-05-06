#include "tilemap.h"
#include <stdio.h>

int tilemap[MAP_HEIGHT][MAP_WIDTH];

bool LoadMapFromFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        TraceLog(LOG_ERROR, "Fehler beim Öffnen der Datei: %s", filename);
        return false;
    }

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (fscanf(file, "%d", &tilemap[y][x]) != 1) {
                TraceLog(LOG_ERROR, "Fehler beim Einlesen der Map bei (%d, %d)", x, y);
                fclose(file);
                return false;
            }
        }
    }

    fclose(file);
    return true;
}

void DrawTilemap(Texture2D tileset)
{
      
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            int tileID = tilemap[y][x];
            DrawText("DEBUG: Zeichne Tilemap", 10, 10, 20, RED);

            // Farben zur Debug-Hilfe
            DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, Fade(RED, 0.1f));

            Rectangle source = {
                (tileID % 2) * TILE_SIZE,
                (tileID / 2) * TILE_SIZE,
                TILE_SIZE,
                TILE_SIZE
            };

            Vector2 position = { x * TILE_SIZE, y * TILE_SIZE };
            DrawTextureRec(tileset, source, position, WHITE);
        }
    }
}