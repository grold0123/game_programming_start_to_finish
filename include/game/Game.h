#pragma once
//=========================================
#include<iostream>
#include<vector>
#include<string>
#include<SDL3/SDL.h>
#include"game/object.h"
//=========================================
class Game{
public:
    Game(int window_width,int window_height,std::string game_title);   
    bool initialize();                              
    void run_loop();                                
    void shutdown();                                
private:
    //=====================================
    //helper functions for run_loop
    void process_input();       
    void update_game();         
    void generate_output();
    //=========================================
    SDL_Window*game_window;             
    SDL_Renderer*game_renderer;         
    bool is_running;                    
    int window_width, window_height;    
    std::string game_title;
    Object ball;
    Object wall;
    //=========================================
};
//=========================================

