#include <SDL2/SDL.h>
#include <iostream>
#include "classes/Window.cpp"

using std::cout;
using std::endl;

int main(void)
{
    Window *janela = new Window(500,500,"CG");

    janela->sinDraw(5,0.5);

    janela->show();


    return 0;
}
