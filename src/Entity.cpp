#include "Entity.h"

void Entity::setEntityColor(sf::Color color_)
{
    this->clr = color_;
}

void Entity::setEntityPos(sf::Vector2f pos_)
{
    this->pos = pos_;
}

void Entity::setEntityTexture(const std::string& path)
{
    if (!(this->texture.loadFromFile(path)))
    {
        exit(EXIT_FAILURE);
    }
}

void Entity::setEntitySprite(sf::Sprite sprite)
{
    this->sprite = sprite;
}

sf::Color Entity::getEntityColor() 
{
    return this->clr;
}

sf::Vector2f Entity::getEntityPos()
{
    return this->pos;
}


sf::Sprite Entity::getEntitySprite()
{
    return this->sprite;
}

sf::Sprite Entity::initEntity() 
{
    
    this->sprite.setTexture(this->texture);
    this->sprite.setScale(0.5f,0.5f);
    this->sprite.setPosition(this->pos);
    return this->sprite;
}

void Entity::draw(sf::RenderWindow& w)
{
    
    w.draw(initEntity());
}