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
            sf::Vector2f position;

        public:
            void setSize(sf::Vector2f n_size);
            void setPosition(sf::Vector2f n_pos);
            sf::Sprite setSprite();
            sf::Vector2f getPosition();

        public:
            void addActionListiener(std::function<void(void)> func);
            void draw(sf::RenderWindow& window);
    };
}

#endif