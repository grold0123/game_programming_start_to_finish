#include<game/object.h>


//================================================================
Object::Object(float x ,float y ,float width, float height):
frect{x,y,width,height},
position{x,y}
{}
//================================================================
void Object::draw(SDL_Renderer*renderer,int r ,int g ,int b ,int a){
    SDL_SetRenderDrawColor(renderer,r,g,b,a);
    SDL_RenderFillRect(renderer,&this->frect);
}
//================================================================
