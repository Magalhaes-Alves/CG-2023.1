#include <SDL2/SDL.h>
#include <iostream>
#include "classes/Window.cpp"

using std::cout;
using std::endl;

int main(void)
{
    Window *janela = new Window(500,500,"CG");

    /* // Maior 45°
    janela->bresenham(50,50,150,450);

    //Igual a 45°
    janela->bresenham(50,50,300,300);

    //Menor que 45°
    janela->bresenham(50,50,450,150);

    janela->bresenham(150,450,450,150); */

    int xi,yi,xf,yf;

    xi = 10;
    yi = 10;
    xf = 50;
    yf = 100;

    janela->ddaLine(xi,yi,xf,yf,255,0,0,255);
    janela->bresenham(xi+20,yi+20,xf+20,yf+20,0,255,0,255);


    janela->show();


    return 0;
}
