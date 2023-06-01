#include "window.h"
#include "player.h"

void MainWindow::setBounds(const std::uint32_t& w , const std::uint32_t& h)
{
	this->width = w;
	this->height = h;
}

void MainWindow::setColor(const sf::Color& clr)
{
    this->color = clr;
}

std::uint32_t MainWindow::getWidth()
{
	return this->width;
}

std::uint32_t MainWindow::getHeight()
{
	return this->height;
}

void MainWindow::start()
{
    sf::RenderWindow window(sf::VideoMode(this->width, this->height), TITLE);

    /* init player*/
    Player pl;
    pl.setColor(Color::Blue);
    pl.setPos(0.0,0.0);
    pl.setSize(50,50);
    pl.setSpeed(2.0f);
    /*------------*/

    while (window.isOpen())
    {
        window.setFramerateLimit(120);
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(this->color);
        pl.setMovement();
        pl.draw(window);
        window.display();
    }

    
    
}