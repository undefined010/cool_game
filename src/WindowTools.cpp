#include "WindowTools.h"

void GUI::Button::addActionListiener(std::function<void(void)> func)
{
    func();
}

void GUI::Button::setPosition(sf::Vector2f n_pos)
{
    this->position = n_pos;
}

sf::Vector2f GUI::Button::getPosition()
{
    return this->position;
}

sf::Sprite GUI::Button::setSprite()
{
    if (!(this->btn_texture.loadFromFile("/Users/ahmadodeh/Coding/cool_game/src/imgs/pause_button.png")))
        exit(EXIT_FAILURE);
    this->btn_sprite.setTexture(this->btn_texture);
    this->btn_sprite.setPosition(this->position);

    return this->btn_sprite;

}

void GUI::Button::draw(sf::RenderWindow& window)
{
    window.draw(this->setSprite());
}