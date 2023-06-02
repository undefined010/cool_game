#ifndef PLAYER_H
#define PLAYER_H

#include "window.h"

using sf::Color;

#define SPEED 2.5f;

class Player 
{

private:
    sf::Vector2f posNew;

private:
    sf::RectangleShape player;
    sf::Vector2f size {};
    sf::Vector2f pos  {};
    sf::Color clr {};

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Image img;

private:
    float velo = SPEED;

public:
    void setColor(const sf::Color& clor);
    void setPos(float x , float y);
    void setSize(float w , float h);
    void setSpeed(float v);
    //void collision(sf::Vector2f r);

public:
    sf::Vector2f getPos();

public:
    sf::Sprite setImg(const std::string& path);

public:
    void setMovement();

public:
    void draw(sf::RenderWindow& window);
};

#endif