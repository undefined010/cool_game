#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>

class Entity {

private:
    float xrate_of_change {3.5f};
    float yrate_of_change {3.5f};
    float Health {100.0f};

private:
    sf::Vector2f pos;
    sf::Vector2f size;
    sf::Color clr;
    sf::Texture texture;
    sf::Sprite sprite;


public:
    void setEntityPos(sf::Vector2f pos_);
    void setEntityColor(sf::Color color_);
    void setEntityTexture(const std::string& path);
    void setEntitySprite(sf::Sprite sprite_);
    void setHealth(float helth_);

public:
    sf::Vector2f getEntityPos();
    sf::Color getEntityColor();
    sf::Sprite getEntitySprite();
    sf::Sprite initEntity();

public:
    void draw(sf::RenderWindow& w);
    void movement();

};

#endif