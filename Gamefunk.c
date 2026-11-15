//
// Created by matth on 10.11.2026.
//
#include "raylib.h"
#include "Gamefunk.h"
#include "raymath.h"


void TakeInput(Input *input) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        input->shoot=1;
    }
    else {
        input->shoot=0;
    }

    if (IsKeyDown(KEY_W) && !IsKeyDown(KEY_S)) {
        input->move.y=-1;
    }
    else if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_W)) {
        input->move.y=1;
    }
    else {
        input->move.y=0;
    }

    if (IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) {
        input->move.x=-1;
    }
    else if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
        input->move.x=1;
    }
    else {
        input->move.x=0;
    }

    input->mousepos = GetMousePosition();
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

void PlayerUpdate(Player *player, const Input *input,const float *dt) {
    player->velocity=Vector2Scale(Vector2Normalize(input->move),player->velMult);
    player->position = Vector2Add(Vector2Scale(player->velocity,*dt), player->position);
    player->mousePosP= Vector2Subtract(input->mousepos, player->position);
    player->view = Vector2Normalize(player->mousePosP);
    player->angle = atan2f(player->view.y,player->view.x) * RAD2DEG;
}

void GameRender(const Player *player) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircleV(player->position, 50, RED);
    DrawLineV(player->position, Vector2Add(player->position, Vector2Scale(player->view,20)),BLUE);
    EndDrawing();
}

void GameInit(Game *game , Screen *screen) {
    for (int i = 0; i<MAX_PLAYERS; i++) {
        if (game->players[i].connected == false) {
            game->localId = i;
        }
    }
    game->players[game->localId].position = screen->middle;
    game->players[game->localId].velMult = 300;

}