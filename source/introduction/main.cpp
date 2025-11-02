//===============================================
//INTRODUCTION
//===============================================
#include"game/Game.h"
//===============================================
int main(
    int argc, char** argv
){
    Game game(800,520,"Game Programming in C++ (Chapter 1)");
    bool success = game.initialize();

    if (success) {
        game.run_loop();
    }

    game.shutdown();

    return 0;

}
//===============================================