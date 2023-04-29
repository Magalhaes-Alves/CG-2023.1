#include <iostream>
#include "../classes/Window.cpp"

int main(void){

    Window* janela = new Window(500,500,"Circle Test");

    janela->drawCircle(0,0,100);
    janela->drawCircle(500,500,100);

    janela->show();

}