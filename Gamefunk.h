//
// Created by matth on 10.11.2026.
//



#ifndef GAME_GAMEFUNK_H
#define GAME_GAMEFUNK_H
#include "raymath.h"
#include "raylib.h"


//------------------Structs------------------

typedef struct Player {
    int id;
    float velMult ;
    Vector2 position;
    Vector2 velocity;
    Vector2 view;
}Player;

typedef struct Input {
    Vector2 move;
    Vector2 angleV2;
    Vector2 mousepos;
    Vector2 mouseposP;
    float angle;
    bool shoot;
}Input;

typedef struct Screen {
    Vector2 size;
    Vector2 middle;
}Screen;



//------------------Funktions----------------
void TakeInput(Input *input, const Player *player);

void setup();

void QuitGame();

void ScreenSize(Screen *screen);

void PlayerUpdate(Player *player, const Input *input, const float *dt);

void GameRender(const Player *player);



#endif //GAME_GAMEFUNK_H