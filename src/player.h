#ifndef PLAYER_H
#define PLAYER_H

#include "window.h"

using sf::Color;

#define SPEED 50;

class Player 
{

private:
    sf::RectangleShape player;
    sf::Vector2f size {};
    sf::Vector2f pos  {};
    sf::Color clr {};

private:
    float velo {0.0f};

public:
    void setColor(const sf::Color& clor);
    void setPos(float x , float y);
    void setSize(float w , float h);
    void setSpeed(float v);

public:
    void setMovement(sf::Event& e);

private:
    sf::RectangleShape initPlayer();

public:
    void draw(sf::RenderWindow& window);
};

#endif