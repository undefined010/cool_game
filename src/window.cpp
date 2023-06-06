#include "player.h"
#include "Entity.h"

MainWindow::~MainWindow()
{
    printf("\n--Main Window destroyed--\n");
}

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

    texture_window.loadFromFile("/Users/ahmadodeh/Coding/cool_game/src/imgs/space_window.png");
    sprite_window.setTexture(texture_window);
    sprite_window.scale(7.5f,8.5f);

    /* init player*/
    Player pl;
    pl.setColor(Color::Blue);
    pl.setPos((width / 2) - 80, height / 2);
    pl.setSize(100,50);
    pl.setSpeed(2.0f);
    /*------------*/

    /* test entity */

    Entity en;
    en.setEntityPos(sf::Vector2f(0,0));
    en.setEntityTexture("/Users/ahmadodeh/Coding/cool_game/src/imgs/spaceship3.png");

    /*************/


    while (window.isOpen())
    {
        window.setFramerateLimit(120);
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if ((event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ))
            {
                window.close();
                exit(EXIT_SUCCESS);
            }
        }
        window.clear();
        window.draw(sprite_window);
        en.draw(window);
        pl.setMovement();
        pl.draw(window);

        window.display();
    }

    
    
}