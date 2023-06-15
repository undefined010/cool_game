#ifndef PLAYER_H
#define PLAYER_H

#include "window.h"
#include "Entity.h"

using sf::Color;

#define SPEED 2.5f;

class Player
{

private:
    /* laser set up */
    float Health{100.0f};
    float laser_dmg{1.0f};
    float laser_vel{6.0f};
    sf::Texture laser_txture;
    sf::Sprite laser_sprite;

private:
    sf::Vector2f posNew;

private:
    sf::RectangleShape player;
    sf::Vector2f size{};
    sf::Vector2f pos{};
    sf::Color clr{};

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Image img;

private:
    float velo = SPEED;

public:
    void setColor(const sf::Color &clor);
    void setPos(float x, float y);
    void setSize(float w, float h);
    void setSpeed(float v);
    void collision();

public:
    sf::Vector2f getPos();
    sf::Sprite setImg(const std::string &path);
    void setMovement();
    void shootLaser(sf::RenderWindow &window);
    void collosionLaser(Entity en);

public:
    void draw(sf::RenderWindow &window);
};

#endif