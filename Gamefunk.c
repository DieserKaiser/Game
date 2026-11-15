//
// Created by matth on 10.11.2026.
//
#include "raylib.h"
#include "Gamefunk.h"
#include "raymath.h"


void TakeInput(Input *input ,const Player *player) {
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
    input->mouseposP= Vector2Subtract(GetMousePosition(), player->position);
    input->angleV2 = Vector2Normalize(input->mouseposP);
    input->angle = atan2f(input->angleV2.y,input->angleV2.x) * RAD2DEG;



}

void setup() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1,1,"Game");
    ToggleBorderlessWindowed();
    SetTargetFPS(60);
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
    player->velocity = Vector2Scale(Vector2Scale(Vector2Add(player->velocity, input->move),player->velMult),*dt);
    player->position = Vector2Scale(Vector2Add(player->position,player->velocity),*dt);
    player->view = input->angleV2;
}

void GameRender(const Player *player) {
    BeginDrawing();
    DrawCircleV(player->position, 50, RED);
    EndDrawing();
}