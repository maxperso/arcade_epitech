/*
** EPITECH PROJECT, 2023
** smfl lib C++ file
** File description:
** sfml
*/

#include "SFML.hpp"
#include "../IGraphicLib.hpp"

namespace Arcade {

    extern "C" Arcade::IGraphicLib *getInstance()
    {
        return new SFML();
    }

    SFML::SFML()
    {
       
    }
    SFML::~SFML()
    {
       
    }

    void SFML::popWindow(std::string const& title, int width, int height)
    {
        width = width * 10;
        height = height * 20;
        this->lib_count = 0;
        window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Resize);
    }

    Keys SFML::getLastEvent()
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    return Arcade::Keys::ESC;
                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Left:
                            return Arcade::Keys::LEFT;
                        case sf::Keyboard::Right:
                            return Arcade::Keys::RIGHT;
                        case sf::Keyboard::Up:
                            return Arcade::Keys::UP;
                        case sf::Keyboard::Down:
                            return Arcade::Keys::DOWN;
                        case sf::Keyboard::Return:
                            return Arcade::Keys::ENTER;
                        case sf::Keyboard::Space:
                            return Arcade::Keys::SPACE;
                        case sf::Keyboard::BackSpace:
                            return Arcade::Keys::BACKSPACE;
                        case sf::Keyboard::Escape:
                            return Arcade::Keys::ESC;
                        case sf::Keyboard::M:
                            return Arcade::Keys::M;
                        case sf::Keyboard::R:
                            return Arcade::Keys::R;
                        case sf::Keyboard::L:
                            return Arcade::Keys::L;
                        case sf::Keyboard::G:
                            return Arcade::Keys::G;
                        case sf::Keyboard::Q:
                            return Arcade::Keys::Q;
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

    void SFML::drawText(std::string text, int x, int y)
    {
        x = x * 32;
        y = y * 32;
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/PublicPixel-z84yD.ttf")) {
            return;
        }
        sf::Text sfmlText;
        sfmlText.setFont(font);
        sfmlText.setString(text);
        sfmlText.setCharacterSize(24);
        sfmlText.setFillColor(sf::Color::Yellow);
        sfmlText.setPosition(x, y);

        sf::FloatRect textBounds = sfmlText.getLocalBounds();
        sf::RectangleShape clearRect(sf::Vector2f(textBounds.width, textBounds.height));
        clearRect.setFillColor(sf::Color::Black);
        clearRect.setPosition(x, y);
        window.draw(clearRect);
        window.draw(sfmlText);
    }

    void SFML::mapManager(Assets &a, int x, int y)
    {
        x++;
        x = x * 32;
        y = y * 32;

        sf::Texture texture;
        if (!texture.loadFromFile(a.image_path))
            exit (42);

        sf::Sprite sprite(texture);
        sprite.setPosition(y, x);
        window.draw(sprite);
    }

    int SFML::select(Arcade::Keys key)
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

    void SFML::closeWindow()
    {
        window.close();
    }

    void SFML::refresh()
    {
        window.display();
    }

    std::string SFML::getName() const
    {
        return "SFML";
    }
}
