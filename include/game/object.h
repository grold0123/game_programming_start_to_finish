#pragma once
//========================================================
#include<SDL3/SDL.h>
//========================================================
class Object{
public:
    
    Object(float x ,float y ,float width, float height);
    void draw(SDL_Renderer*renderer,int r=255,int g=255,int b=255,int a=255);
private:
    struct vector2{
        float x ; 
        float y;
    };
    SDL_FRect frect;    
    vector2 position;
};
//========================================================