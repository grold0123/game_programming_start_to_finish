#include<game/object.h>


//================================================================
Object::Object(float x ,float y ,float width, float height):
frect{x,y,width,height}
{}
//================================================================
void Object::draw(SDL_Renderer*renderer,int r ,int g ,int b ,int a){
    SDL_SetRenderDrawColor(renderer,r,g,b,a);
    SDL_RenderFillRect(renderer,&this->frect);
}
//================================================================
void Object::move(float delta_time){
    if (this->movement != STILL){
        float movespeed = 300.0f * delta_time;        
        std::cout << movespeed << std::endl;
        switch (this->movement){                    
            case UP: 
                frect.y -= movespeed;
                break;
            case DOWN: 
                frect.y += movespeed;
                break;
        }     
    }        
    if (this->movement == BOUNCE){
        this->frect.x += this->velocity.x * delta_time;
        this->frect.y += this->velocity.y * delta_time;
    }
}