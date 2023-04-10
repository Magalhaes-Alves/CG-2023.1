#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

using std::cout;
using std::string;
using std::uint8_t;

class Window{

    bool isRunning;    
    SDL_Window * window;
    int width;
    int height;
    SDL_Renderer * renderer;

    public:
        Window() {
            Window(1000,1000,"");    
        }
        //Defini por padrão setar o fundo preto e renderer branco
        Window(int width,int height, const char* title){
            
            if (SDL_Init(SDL_INIT_VIDEO)<0){
                throw std::runtime_error("Não foi possível inicializar o SDL2.");
            }
            this->window = SDL_CreateWindow(
                title,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                width,
                height,
                SDL_WINDOW_RESIZABLE
            );
            if (this->window ==NULL){
                throw std::runtime_error("Não foi possível criar a janela.");
            }
            this->height=height;
            this->width= width;

            this->renderer = SDL_CreateRenderer(this->window,-1,0);
            
            SDL_SetRenderDrawColor(this->renderer,0,0,0,255);

            SDL_RenderClear(this->renderer);

            SDL_SetRenderDrawColor(this->renderer,255,255,255,255);
        }

        int getWidth(){
            return this->width;
        }

        int getHeight(){
            return this->height;
        }

        void setColor(int r,int g,int b, int alpha){
            SDL_SetRenderDrawColor(this->renderer,r,g,b,alpha);
        }

        void setPixel(int x,int y, unsigned char r,unsigned char g,unsigned char b ,unsigned char alpha){

            this->setColor(r,g,b,alpha);          
            this->setPixel(x,y);
        }

        void setPixel(int x,int y){

            x = (x<0) ? 0:x;
            y = (y<0) ? 0:y;
            x = (x>= this->getWidth()) ? this->getWidth()-1 :x;
            y = (y>= this->getHeight()) ? this->getHeight()-1:y;

            SDL_RenderDrawPoint(this->renderer,x,y);
        }

        void sinDraw(double amplitude,double frequency){
            int y;
            for (int x=0;x<this->getWidth();x++){
                y = (int) this->getHeight()/2 + amplitude*sin(x*frequency);
                this->setPixel(x,y);
            }
        }
        
        void bresenham(double xi,double yi, double xf , double yf, unsigned char r,unsigned char g,unsigned char b,unsigned char alpha){
            SDL_SetRenderDrawColor(this->renderer,r,g,b,alpha);
            bresenham(xi,yi,xf,yf);
        }

        void bresenham(double xi,double yi, double xf , double yf){
            double dx,dy,dx2,dy2,p,aux;
            int x,y;
            bool swap=0;
            
            dx = xf-xi;
            dy= yf-yi;

            dx2 = 2*dx;
            dy2 = 2*dy;

            p = -dx +dy2;
            x =round(xi);
            y=round(yi);

            for (int s=0;s<abs(dx);s++){
                if (swap){
                    this->setPixel(x,y);  
                }else{

                    this->setPixel(y,x);  
                }
                x++;
                if (p>=0){
                    y++;
                    p = p-dx2+dy2;
                }else{
                    p=p+dy2;
                }
            }
        }

        void ddaLine(double xi,double yi, double xf, double yf, unsigned char r,unsigned char g,unsigned char b,unsigned char alpha){
            SDL_SetRenderDrawColor(this->renderer,r,g,b,alpha);
            this->ddaLine(xi,yi,xf,yf);
        }

        void ddaLine(double xi,double yi, double xf, double yf){
            double dx,dy,steps_x,steps_y;
            int steps,x,y;

            dx = xf -xi;
            dy = yf-yi;

            steps = abs(dx);

            if (steps ==0){
                this->setPixel(xi,yi);
                return;
            }

            if (fabs(dy)> fabs(dx)){
                steps=abs(dy);
            }

            steps_x = dx/steps;
            steps_y = dy/steps;

            for (int s=0;s<steps;s++){
                x = round(xi +s*steps_x);
                y = round(yi +s*steps_y);
                this->setPixel(x,y);
            }

        }

        void drawLine(double xi, double yi, double xf,double yf){
            int x,y;
            double dy,dx,a,vy,aux;
            bool trocou;

            dx = xf-xi;
            dy = yf-yi;

            if (dx ==0 && dy ==0){
                this->setPixel(xi,yi);
                return;
            }
            trocou=0;
            if (fabs(dy)> fabs(dx)){
                aux = dx;
                dx = dy;
                dy=aux;
                aux =xi;
                xi=yi;
                yi=aux;
                trocou =1;
            }
            a = dy/dx;

            for (int vx= 0; vx<abs(dx);vx++){

                if (dx<0){
                    vx = -vx;
                }
                vy=a*vx;
                x= round(xi+vx);
                y= round(yi+vy);
                
                if (trocou){
                    this->setPixel(y,x);
                }else{
                    this->setPixel(x,y);
                }
            }
        }

        void show(){
            SDL_RenderPresent(this->renderer);
            this->isRunning=true;
            while(this->isRunning){
                SDL_Event ev;
                while(SDL_PollEvent(&ev)){
                    if (ev.type == SDL_QUIT){
                        this->isRunning=false;
                    }

                }
            }
        }
};

