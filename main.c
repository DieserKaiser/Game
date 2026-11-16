#include "raylib.h"
#include "raymath.h"
#include "Gamefunk.h"

int main() {
    setup();


    Game game = {0};
    Screen screen;
    ScreenSize(&screen);

    GameInit(&game,&screen);
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        TakeInput(&game.inputs[game.localId]);
        PlayerUpdate(&game.players[game.localId],&game.inputs[game.localId],&dt);
        GameRender(&game);


    }
    QuitGame();

}