#include "WindowTools.h"

bool::GUI::Button::isMouseInPosition(sf::RenderWindow& win)
{
    bool xCords = sf::Mouse::getPosition(win).x <= 1600 && sf::Mouse::getPosition(win).x >= 1600-32;
    bool yCords = sf::Mouse::getPosition(win).y >= this->getPosition().y && sf::Mouse::getPosition(win).y <= 32;

    if (xCords && yCords) return true;
    else return false;
}

void GUI::Button::addActionListiener(std::function<void(void)> func , sf::RenderWindow& win)
{

    if (this->isMouseInPosition(win) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        func();
    }
}

void GUI::Button::setPosition(sf::Vector2i n_pos)
{
    this->position = n_pos;
}

sf::Vector2i GUI::Button::getPosition()
{
    return this->position;
}

sf::Sprite GUI::Button::setSprite()
{
    if (!(this->btn_texture.loadFromFile("/Users/ahmadodeh/Coding/cool_game/src/imgs/pause_button.png")))
        exit(EXIT_FAILURE);
    this->btn_sprite.setTexture(this->btn_texture);
    this->btn_sprite.setPosition(sf::Vector2f(static_cast<float>(this->position.x) , static_cast<float>(this->position.y)));

    return this->btn_sprite;

}

void GUI::Button::draw(sf::RenderWindow& window)
{
    printf("x : %i , y : %i\n",sf::Mouse::getPosition(window).x , sf::Mouse::getPosition(window).y);
    window.draw(this->setSprite());
}