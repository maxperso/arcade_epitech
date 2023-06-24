/*
** EPITECH PROJECT, 2023
** sdl lib C++ file
** File description:
** sfml
*/

#include "SDL.hpp"
#include "../IGraphicLib.hpp"

namespace Arcade {

    SDL::SDL()
    {
       
    }
    SDL::~SDL()
    {
       
    }

    extern "C" Arcade::IGraphicLib *getInstance()
    {
        return new SDL();
    }

    void SDL::popWindow(std::string const& title, int width, int height)
    {
        width = width*10;
        height = height*20;
        this->lib_count = 0;
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL could not initialize video: " << SDL_GetError() << std::endl;
            return;
        }

        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if (!window) {
            std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!renderer) {
            std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
            SDL_DestroyWindow(window);
            SDL_Quit();
            return;
        }
    }

    Keys SDL::getLastEvent()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return Arcade::Keys::ESC;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_a:
                            return Arcade::Keys::A;
                        case SDLK_b:
                            return Arcade::Keys::B;
                        case SDLK_c:
                            return Arcade::Keys::C;
                        case SDLK_d:
                            return Arcade::Keys::D;
                        case SDLK_e:
                            return Arcade::Keys::E;
                        case SDLK_f:
                            return Arcade::Keys::F;
                        case SDLK_g:
                            return Arcade::Keys::G;
                        case SDLK_h:
                            return Arcade::Keys::H;
                        case SDLK_i:
                            return Arcade::Keys::I;
                        case SDLK_j:
                            return Arcade::Keys::J;
                        case SDLK_k:
                            return Arcade::Keys::K;
                        case SDLK_l:
                            return Arcade::Keys::L;
                        case SDLK_m:
                            return Arcade::Keys::M;
                        case SDLK_n:
                            return Arcade::Keys::N;
                        case SDLK_o:
                            return Arcade::Keys::O;
                        case SDLK_p:
                            return Arcade::Keys::P;
                        case SDLK_q:
                            return Arcade::Keys::Q;
                        case SDLK_r:
                            return Arcade::Keys::R;
                        case SDLK_s:
                            return Arcade::Keys::S;
                        case SDLK_t:
                            return Arcade::Keys::T;
                        case SDLK_u:
                            return Arcade::Keys::U;
                        case SDLK_v:
                            return Arcade::Keys::V;
                        case SDLK_w:
                            return Arcade::Keys::W;
                        case SDLK_x:
                            return Arcade::Keys::X;
                        case SDLK_y:
                            return Arcade::Keys::Y;
                        case SDLK_z:
                            return Arcade::Keys::Z;
                        case SDLK_LEFT:
                            return Arcade::Keys::LEFT;
                        case SDLK_RIGHT:
                            return Arcade::Keys::RIGHT;
                        case SDLK_UP:
                            return Arcade::Keys::UP;
                        case SDLK_DOWN:
                            return Arcade::Keys::DOWN;
                        case SDLK_RETURN:
                            return Arcade::Keys::ENTER;
                        case SDLK_SPACE:
                            return Arcade::Keys::SPACE;
                        case SDLK_BACKSPACE:
                            return Arcade::Keys::BACKSPACE;
                        case SDLK_ESCAPE:
                            return Arcade::Keys::ESC;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        return Arcade::Keys::NONE;
    }

    void SDL::drawText(std::string text, int x, int y)
    {
        x = x * 32;
        y = y * 32;
        SDL_Renderer* renderer = SDL_GetRenderer(window);

        if (TTF_Init() != 0)
        {
            std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
            SDL_Quit();
            return;
        }
        TTF_Font* font = TTF_OpenFont("assets/fonts/PublicPixel-z84yD.ttf", 24);

        SDL_Color color = { 252, 211, 3, 255 }; //Yellow
        SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        int width, height;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);

        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = width;
        rect.h = height;

        SDL_RenderCopy(renderer, texture, NULL, &rect);

        SDL_FreeSurface(surface);
        TTF_Quit();
        SDL_DestroyTexture(texture);
    }

    void SDL::mapManager(Assets &a, int x, int y)
    {
        x++;
        x = x * 32;
        y = y * 32;
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, IMG_Load(a.image_path.c_str()));
        if (!texture) {
            std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return;
        }
        
        SDL_Rect destRect = { y, x, a.width, a.height };

        SDL_RenderCopy(renderer, texture, NULL, &destRect);

        SDL_DestroyTexture(texture);
    }

    int SDL::select(Arcade::Keys key)
    {
        if (key == Arcade::Keys::DOWN) {
            this->lib_count++;
        } else if (key == Arcade::Keys::UP) {
            this->lib_count--;
        }
        if (this->lib_count == -1)
            this->lib_count = 4;
        if (this->lib_count == 5)
            this->lib_count = 0;
        return this->lib_count;
    }

    void SDL::closeWindow()
    {
        if (renderer != nullptr) {
            SDL_DestroyRenderer(renderer);
            renderer = nullptr;
        }

        if (window != nullptr) {
            SDL_DestroyWindow(window);
            window = nullptr;
        }

        SDL_Quit();
    }

    void SDL::refresh()
    {
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    std::string SDL::getName() const
    {
        return "SDL";
    }

}
