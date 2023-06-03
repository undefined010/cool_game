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

void Player::collision()
{
    std::uint32_t w_windo = WIDTH;

    if (player.getPosition().x >= (w_windo - 150))
    {
        /* this code fixed a glith */
        pos.x = w_windo - 150;
        pos.y = player.getPosition().y;
        player.setPosition(pos);
    }

    if (player.getPosition().x <= 10)
    {
        pos.x = 10;
        pos.y = player.getPosition().y;
        player.setPosition(pos);
    }

    if (player.getPosition().y <= 0) {
        pos.x = player.getPosition().x;
        pos.y = 0;
        player.setPosition(pos);
    }

    if (player.getPosition().y >= 1140)
    {
        pos.x = player.getPosition().x;
        pos.y = 1140;
        player.setPosition(pos);
    }

    
}

void Player::draw(sf::RenderWindow& window)
{
    collision();
    printf("x : %0.2f , y : %0.2f\n",player.getPosition().x , player.getPosition().y);
    window.draw(setImg("/Users/ahmadodeh/Coding/cool_game/src/imgs/spaceship2.png"));
}