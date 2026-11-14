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
        input->move.y=1;
    }
    else if (IsKeyDown(KEY_S) && !IsKeyDown(KEY_W)) {
        input->move.y=-1;
    }
    else {
        input->move.y=0;
    }

    if (IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) {
        input->move.x=1;
    }
    else if (IsKeyDown(KEY_D) && !IsKeyDown(KEY_A)) {
        input->move.x=-1;
    }
    else {
        input->move.x=0;
    }


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