    #include"game/Game.h"

    Game::Game(int window_width,int window_height,std::string game_title):
        game_window(nullptr),
        is_running(true),
        game_renderer(nullptr),
        window_width(window_width),
        window_height(window_height),
        game_title(game_title),
        ball(window_width/2.0f,window_height/2.0f,15,15),
        wall(0,window_height/4.0f,15,200),
        wall_2(window_width-15,window_height/4.0f,15,200),
        tick_count(0)
    {
        this->ball.movement = BOUNCE;
        this->ball.velocity = {-200.0f,235.0f};
    }

    bool Game::initialize(){    
        //===============================================================
        
        //===============================================================
        if (!SDL_Init(SDL_INIT_VIDEO)){
            SDL_Log("Unable to initialize SDL: %s",SDL_GetError);
            return false;
        }
        //===============================================================
        this->game_window = SDL_CreateWindow(
            (game_title).c_str(), 
            window_width,   
            window_height,  
            0               
        );
        if (!this->game_window){  
            SDL_Log("Failed to create window: %s",SDL_GetError);
            return false;
        }
        //===============================================================
        this->game_renderer = SDL_CreateRenderer(
            this->game_window,    
            NULL                  
        );
        if (!this->game_renderer){
            SDL_Log("Failed to create renderer: %s",SDL_GetError);
            return false;
        }    
        //===============================================================
        
        return true;
    }

    void Game::shutdown(){
        SDL_DestroyRenderer(this->game_renderer);
        SDL_DestroyWindow(this->game_window);
        SDL_Quit();
    }

    void Game::run_loop(){
        while(this->is_running){
            this->process_input();
            this->update_game();
            this->generate_output();
        }
    }

    void Game::process_input(){
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT: this->is_running = false;break;
                case SDL_EVENT_KEY_DOWN: 
                    switch (event.key.key) {
                        //=====================================
                        //close game
                        case SDLK_ESCAPE: this->is_running = false; break;
                        //=====================================
                        //move up
                        case SDLK_W  : std::cout << "Pressed W Key\n"; this->wall.movement = UP;
                        case SDLK_UP : std::cout << "Pressed UP key\n"; this->wall_2.movement = UP;break;
                        //=====================================
                        //move down
                        case SDLK_S  : std::cout << "Pressed S Key\n"; this->wall.movement = DOWN;
                        case SDLK_DOWN : std::cout << "Pressed DOWN key\n"; this->wall_2.movement = DOWN;break;
                        //=====================================
                        case SDLK_A  : std::cout << "Pressed A Key\n"; break;                    
                        case SDLK_D  : std::cout << "Pressed D Key\n"; break;                                                
                    };
                    break;                    
                case SDL_EVENT_KEY_UP : 
                    switch (event.key.key) {
                        case SDLK_W :case SDLK_S : this->wall.movement = STILL; break;
                        case SDLK_UP :case SDLK_DOWN : this->wall_2.movement = STILL; break;
                    };
                    break;                                    
            }
        }
    }

    void Game::update_game(){

        //delta time , difference in ticks from last 
        float delta_time = (SDL_GetTicks() - this->tick_count)/ 1000.0f;
        this->tick_count = SDL_GetTicks();
        
        this->ball.move(delta_time);
        this->wall.move(delta_time);
        this->wall_2.move(delta_time);
    }

    void Game::generate_output(){
        //========================================================================
        //clear the back buffer to a color
        SDL_SetRenderDrawColor(                 
            this->game_renderer,                //renderer
            000,                                //R
            000,                                //G
            255,                                //B
            255                                 //A
        );
        //========================================================================
        SDL_RenderClear(this->game_renderer);
        this->ball.draw(game_renderer);
        this->wall.draw(game_renderer);
        this->wall_2.draw(game_renderer);
        //========================================================================
        SDL_RenderPresent(this->game_renderer);
        //========================================================================
    }
