#include "player.h"

void Player::setColor(const sf::Color& clor) 
{
    clr = clor;
}

void Player::setPos(float x , float y)
{
    pos.x = x;
    pos.y = y;
}

void Player::setSize(float w , float h)
{
    size.x = w;
    size.y = h;
}

sf::Sprite Player::setImg(const std::string& path)
{
    if (!(img.loadFromFile(path))) exit(EXIT_FAILURE);

    img.createMaskFromColor(sf::Color::White); // need to be fixed later

    if (!(texture.loadFromImage(img))) exit(EXIT_FAILURE);

    sprite.setTexture(texture);
    sprite.setPosition(player.getPosition());
    sprite.setScale(0.5f,0.5f);
    // sprite.setRotation(180.0f); later 
    // sprite.rotate(180.0f);      later

    return sprite;
}

sf::Vector2f Player::getPos()
{
    return pos;
}

void Player::setSpeed(float v)
{
    velo = v;
}

void Player::setMovement()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) pos.y -= velo;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) pos.y += velo;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) pos.x += velo;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) pos.x -= velo;;
    player.setPosition(pos);
}


void Player::draw(sf::RenderWindow& window)
{
    window.draw(setImg("/Users/ahmadodeh/Coding/cool_game/src/imgs/spaceship2.png"));
}