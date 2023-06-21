#ifndef WINDOWTOOLS_H_
#define WINDOWTOOLS_H_

#include <SFML/Graphics.hpp>
#include <functional>

namespace GUI
{

    class Button 
    {
        private:
            sf::Sprite btn_sprite;
            sf::Texture btn_texture;
            sf::Vector2i position;

        public:
            void setSize(sf::Vector2f n_size);
            void setPosition(sf::Vector2i n_pos);
            sf::Sprite setSprite();
            sf::Vector2i getPosition();

        public:
            void addActionListiener(std::function<void(void)> func , sf::RenderWindow& win);
            void draw(sf::RenderWindow& window);

        private:
            bool isMouseInPosition(sf::RenderWindow& win);
    };
}

#endif