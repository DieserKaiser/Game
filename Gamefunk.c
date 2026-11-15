//
// Created by matth on 10.11.2026.
//
#include "raylib.h"
#include "Gamefunk.h"
#include "raymath.h"


void TakeInput(Game *game) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        game->inputs[game->localId].shoot=1;
    }
    else {
        game->inputs[game->localId].shoot=0;
    }

    if (IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)) {
        game->inputs[game->localId].move.y=-1;
    }
    else if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_W)) {
        game->inputs[game->localId].move.y=1;
    }
    else {
        game->inputs[game->localId].move.y=0;
    }

    if (IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) {
        game->inputs[game->localId].move.x=-1;
    }
    else if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
        game->inputs[game->localId].move.x=1;
    }
    else {
        game->inputs[game->localId].move.x=0;
    }

   game->inputs[game->localId].mousepos = GetMousePosition();
}

void setup() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1,1,"Game");
    ToggleBorderlessWindowed();
    SetTargetFPS(500);
    InitAudioDevice();
    SetExitKey(0);
}



void QuitGame() {
    CloseWindow();
    CloseAudioDevice();
}

void ScreenSize(Screen *screen) {
    screen->size.x = (float)GetScreenWidth();
    screen->size.y = (float)GetScreenHeight();
    screen->middle = Vector2Scale(screen->size,0.5f);
}

void PlayerUpdate(Game *game, const float *dt) {
    game->players[game->localId].velocity=Vector2Scale(Vector2Normalize(game->inputs[game->localId].move),game->players[game->localId].velMult);
    game->players[game->localId].position = Vector2Add(Vector2Scale(game->players[game->localId].velocity,*dt), game->players[game->localId].position);
    game->players[game->localId].mousePosP= Vector2Subtract(game->inputs[game->localId].mousepos, game->players[game->localId].position);
    game->players[game->localId].view = Vector2Normalize(game->players[game->localId].mousePosP);
    game->players[game->localId].angle = atan2f(game->players[game->localId].view.y,game->players[game->localId].view.x) * RAD2DEG;
}

void GameRender(const Game *game) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircleV(game->players[game->localId].position, 50, RED);
    DrawLineV(game->players[game->localId].position, Vector2Add(game->players[game->localId].position, Vector2Scale(game->players[game->localId].view,20)),BLUE);
    EndDrawing();
}

void GameInit(Game *game , const Screen *screen) {
    for (int i = 0; i<MAX_PLAYERS; i++) {
        if (game->players[i].connected == false) {
            game->localId = i;
            break;
        }
    }
    game->players[game->localId].connected = 1;
    game->players[game->localId].position = screen->middle;
    game->players[game->localId].velMult = 300;

}