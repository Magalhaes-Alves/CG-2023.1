#include <SDL2/SDL.h>
#include <iostream>
#include "classes/Window.cpp"

using std::cout;
using std::endl;
using std::cin;

int main(void)
{
    int xi,yi,xf,yf;
    Window *janela = new Window(500,500,"CG");
    char option ='s';

    bool cont =true;
        
    cout<< "xi:";
    cin>>xi;

    cout<< "yi:";
    cin>>yi;

    while(cont){

        cout<< "xf:";
        cin>>xf;

        cout<< "yf:";
        cin>>yf;

        janela->drawLine(xi,yi,xf,yf);

        xi = xf;
        yi = yf;

        cout<<"Deseja adicionar outro ponto?\n";
        cin>> option;

        cont = (option =='s');

    }

    return 0;
}
