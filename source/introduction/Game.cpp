    #include"game/Game.h"

    Game::Game(int window_width,int window_height,std::string game_title):
        game_window(nullptr),
        is_running(true),
        game_renderer(nullptr),
        window_width(window_width),
        window_height(window_height),
        game_title(game_title),
        ball(window_width/2.0f,window_height/2.0f,15,15),
        wall(0,window_height/4.0f,15,200)
    {

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
                case SDL_EVENT_KEY_DOWN: switch (event.key.key) {
                    case SDLK_ESCAPE: this->is_running = false; break;
                    case SDLK_W  : std::cout << "Pressed W Key\n"; break;
                    case SDLK_A  : std::cout << "Pressed A Key\n"; break;
                    case SDLK_S  : std::cout << "Pressed S Key\n"; break;
                    case SDLK_D  : std::cout << "Pressed D Key\n"; break;
                }
            }
        }
    }

    void Game::update_game(){
            
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
        //========================================================================
        SDL_RenderPresent(this->game_renderer);
        //========================================================================
    }
