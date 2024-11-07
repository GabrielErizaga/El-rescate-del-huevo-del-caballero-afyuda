#include <windows.h>
#include "game.h"
using namespace std;
using namespace sf;


int main(){
    game game;
    while(game.isRunning()){

       game.update();
       game.render();
    }
}
