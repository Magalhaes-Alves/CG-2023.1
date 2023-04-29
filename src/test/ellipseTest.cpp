#include <iostream>
#include "../classes/Window.cpp"

using std::cin;
using std::cout;

int main(void){
    int rx,ry;
    Window* janela = new Window(500,500,"Ellipse Test");
    cout<<"Rx:\n";
    cin>>rx;
    cout<<"Ry:\n";
    cin>>ry;

    janela->drawEllipse(250,250, rx, ry);

    janela->show();
}