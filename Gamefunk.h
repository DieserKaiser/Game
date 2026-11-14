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
    int velMult ;
    Vector2 position;
    Vector2 velocity;
    Vector2 view;
}Player;

typedef struct Input {
    Vector2 move;
    Vector2 mousepos;
    bool shoot;
}Input;


//------------------Funktions----------------
void TakeInput(Input *input);

void setup();

void QuitGame();


#endif //GAME_GAMEFUNK_H