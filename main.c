#include "raylib.h"
#include "raymath.h"
#include "Gamefunk.h"

int main() {
    setup();

    Screen screen;
    ScreenSize(&screen);
    Player player = {0};
    player.velMult = 50;
    player.position=screen.middle;
    Input input;



    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        TakeInput(&input);
        PlayerUpdate(&player, &input, &dt);
        GameRender(&player);

    }
    QuitGame();

}