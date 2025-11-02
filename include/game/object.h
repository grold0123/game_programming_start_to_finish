#pragma once
//========================================================
#include<SDL3/SDL.h>
#include<iostream>
enum movement{
            UP,DOWN,STILL,BOUNCE
    };
//========================================================
class Object{
public:    
    struct vector2{
        float x; 
        float y;
    };
    vector2 velocity;
    movement movement = STILL;
    Object(float x ,float y ,float width, float height);
    void draw(SDL_Renderer*renderer,int r=255,int g=255,int b=255,int a=255);
    void move(float);
    SDL_FRect get_rect();
private:    
    SDL_FRect frect;            
};
//========================================================