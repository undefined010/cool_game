#include "player.h"
#include "Entity.h"

void Player::setColor(const sf::Color &clor)
{
    clr = clor;
}

void Player::setPos(float x, float y)
{
    pos.x = x;
    pos.y = y;
}

void Player::setSize(float w, float h)
{
    size.x = w;
    size.y = h;
}

sf::Sprite Player::setImg(const std::string &path)
{
    if (!(img.loadFromFile(path)))
        exit(EXIT_FAILURE);

    img.createMaskFromColor(sf::Color::White); // need to be fixed later

    if (!(texture.loadFromImage(img)))
        exit(EXIT_FAILURE);

    sprite.setTexture(texture);
    sprite.setPosition(player.getPosition());
    sprite.setScale(0.5f, 0.5f);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        pos.y -= velo;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        pos.y += velo;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        pos.x += velo;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        pos.x -= velo;

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

    if (player.getPosition().y <= 0)
    {
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

void Player::shootLaser(sf::RenderWindow &window)
{
    if (!(laser_txture.loadFromFile("/Users/ahmadodeh/Coding/cool_game/src/imgs/laser.png")))
        exit(EXIT_FAILURE);

    laser_sprite.setTexture(laser_txture);
    laser_sprite.setPosition(pos.x - 170, pos.y - 250);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        laser_sprite.setPosition(laser_sprite.getPosition().x, laser_sprite.getPosition().y - laser_vel);
        window.draw(laser_sprite);
    }
}

void Player::collosionLaser(Entity en)
{   

    bool yCollide = laser_sprite.getPosition().y <= en.getEntityPos().y + laser_sprite.getScale().y && laser_sprite.getPosition().y >= en.getEntityPos().y - laser_sprite.getScale().y;
   
    bool isPressing = sf::Keyboard::isKeyPressed(sf::Keyboard::X);

    if (yCollide && isPressing)
    {
        printf("\nTEST Y\n");
    }

    //printf("player(%0.2f , %0.2f),laser(%0.2f , %0.2f ), target(%f , %f)\n",pos.x , pos.y,laser_sprite.getPosition().x,laser_sprite.getPosition().y,en.getEntityPos().x , en.getEntityPos().y);
}

void Player::draw(sf::RenderWindow &window)
{
    collision();

    //printf("x : %0.2f , y : %0.2f\n", player.getPosition().x, player.getPosition().y);
    shootLaser(window);
    window.draw(setImg("/Users/ahmadodeh/Coding/cool_game/src/imgs/spaceship1.png"));
}