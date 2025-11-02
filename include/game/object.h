#pragma once
//========================================================
#include<SDL3/SDL.h>
#include<iostream>
enum movement{
            UP,DOWN,STILL
    };
//========================================================
class Object{
public:    
    movement movement = STILL;
    Object(float x ,float y ,float width, float height);
    void draw(SDL_Renderer*renderer,int r=255,int g=255,int b=255,int a=255);
    void move(float);
private:    
    SDL_FRect frect;        
};
//========================================================