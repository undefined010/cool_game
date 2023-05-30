#ifndef PLAYER_H
#define PLAYER_H

#include "window.h"

// just use "using" keyword smh but nvm it's cooler 
#define BLACK sf::Color::Black
#define WHITE sf::Color::White
#define BLUE  sf::Color::Blue

class Player 
{

private:
    sf::RectangleShape player;
    sf::Vector2f size {};
    sf::Vector2f pos  {};
    sf::Color clr {};

public:
    void setColor(const sf::Color& clor);
    void setPos(float x , float y);
    void setSize(float w , float h);


public:
    void setMovement(sf::Event& e);

private:
    sf::RectangleShape initPlayer();

public:
    void draw(sf::RenderWindow& window);
};

#endif