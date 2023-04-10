#include <SDL2/SDL.h>
#include <iostream>
#include "classes/Window.cpp"

using std::cout;
using std::endl;

int main(void)
{
    Window *janela = new Window(500,500,"CG");

    int height,width;
    height = janela->getHeight();
    width = janela->getWidth();


    // Maior 45°
    janela->ddaLine(50,50,150,450);

    //Igual a 45°
    janela->ddaLine(50,50,300,300);

    //Menor que 45°
    janela->ddaLine(50,50,450,150);

    janela->ddaLine(150,450,450,150);

    janela->show();


    return 0;
}
