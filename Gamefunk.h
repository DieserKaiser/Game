//
// Created by matth on 10.11.2026.
//



#ifndef GAME_GAMEFUNK_H
#define GAME_GAMEFUNK_H
#include "raymath.h"
#include "raylib.h"


//------------------Definitions--------------
#define MAX_PLAYERS 4
#define MAX_BULLETS 180

//------------------Structs------------------

typedef struct Player {
    bool connected;
    float velMult ;
    Vector2 position;
    Vector2 velocity;
    Vector2 view;
    Vector2 mousePosP;
    float angle;
}Player;

typedef struct Input {
    Vector2 move;
    Vector2 mousepos;
    bool shoot;
}Input;

typedef struct Screen {
    Vector2 size;
    Vector2 middle;
}Screen;

typedef struct Bullet {
    bool active;
    int ownerId;
    Vector2 pos;
    Vector2 vel;
    float live;
}Bullet;

typedef struct Game {
    int localId;
    Player players[MAX_PLAYERS];
    Bullet bullets[MAX_BULLETS];
    Input inputs[MAX_PLAYERS];
}Game;



//------------------Funktions----------------
void TakeInput(Input *input);

void setup();

void QuitGame();

void ScreenSize(Screen *screen);

void PlayerUpdate(Player *player, const Input *input, const float *dt);

void GameRender(const Game *game);

void GameInit(Game *game, const Screen *screen);



#endif //GAME_GAMEFUNK_H