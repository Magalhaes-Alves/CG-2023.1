#include <SDL2/SDL.h>
#include <iostream>
#include "../classes/Window.cpp"

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

    //1º setor
    janela->bresenham(250,250,200,225,255,0,0,255);
    janela->bresenham(250,250,200,200,0,255,0,255);
    janela->bresenham(250,250,225,200,0,0,255,255);
    
    janela->bresenham(250,250,250,200,255,122,85,255);

    //2º setor
    janela->bresenham(250,250,275,200,0,0,255,255);
    janela->bresenham(250,250,300,200,0,255,0,255);
    janela->bresenham(250,250,300,225,255,0,0,255);

    janela->bresenham(250,250,300,250,255,50,85,255);


    //3º setor
    janela->bresenham(250,250,300,275,255,0,0,255);
    janela->bresenham(250,250,300,300,0,255,0,255);
    janela->bresenham(250,250,275,300,0,0,255,255);

    janela->bresenham(250,250,250,300,255,122,0,255);
 
    //4º setor
    janela->bresenham(250,250,200,275,255,0,0,255);
    janela->bresenham(250,250,200,300,0,255,0,255);
    janela->bresenham(250,250,225,300,0,0,255,255);

    janela->bresenham(250,250,200,250,255,255,255,255);


    janela->show();


    return 0;
}
