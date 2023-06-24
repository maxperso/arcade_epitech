#include "../IGraphicLib.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

//to compile use these flags: -lSDL2 -lSDL2_ttf

namespace Arcade {

    class SDL : public IGraphicLib {
    public:
        SDL();
        ~SDL() override;
        SDL_Window *window;
        SDL_Surface *window_surface;
        SDL_Renderer *renderer;
        int lib_count;
        bool keep_window_open = true;
        int scale_factorx;
        int scale_factory;

        std::string getName() const override;
        void popWindow(std::string const& title, int width, int height) override;
        Keys getLastEvent() override;
        void mapManager(Assets &a, int x, int y) override;
        void drawText(std::string text, int x, int y) override;
        void closeWindow() override;
        int select(Arcade::Keys key) override;
        void refresh() override;

    private:
    };
}