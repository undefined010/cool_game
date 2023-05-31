#include "player.h"

void Player::setColor(const sf::Color& clor) 
{
    this->clr = clor;
}

void Player::setPos(float x , float y)
{
    this->pos.x = x;
    this->pos.y = y;
}

void Player::setSize(float w , float h)
{
    this->size.x = w;
    this->size.y = h;
}

void Player::setSpeed(float v)
{
    this->velo = v;
}

void Player::setMovement(sf::Event& e)
{
    if (this->velo == 0.0f) this->velo = SPEED;

    if (e.type == sf::Event::KeyPressed)
    {
        switch (e.key.code)
        {
        case sf::Keyboard::W:
            this->pos.y -= this->velo;
            break;
        case sf::Keyboard::S:
            this->pos.y += this->velo;
            break;

        case sf::Keyboard::A:
            this->pos.x -= this->velo;
            break;
        case sf::Keyboard::D:
            this->pos.x += this->velo;
            break;
        default:
            break;
        }
    }
}

sf::RectangleShape Player::initPlayer()
{
    this->player.setSize(this->size);
    this->player.setPosition(this->pos);
    this->player.setFillColor(this->clr);

    return this->player;
}

void Player::draw(sf::RenderWindow& window)
{

    window.draw(this->initPlayer());
}