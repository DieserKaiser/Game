#include "raylib.h"
#include "raymath.h"
#include "Gamefunk.h"

int main() {
    setup();

    Screen screen;
    ScreenSize(&screen);
    Player player;
    player.position=screen.middle;
    Input input;



    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        TakeInput(&input, &player);
        PlayerUpdate(&player, &input, &dt);
        GameRender(&player);

    }
    QuitGame();

}