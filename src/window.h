#ifndef WINDOW_H_
#define WINDOW_H_

#include <string_view>


#define HEIGHT 1400
#define WIDTH 1600
#define TITLE "Window Alpha 0.1"
#define COLOR sf::Color::White

#include <SFML/Graphics.hpp>


class MainWindow 
{

private:
	std::uint32_t width {WIDTH};
	std::uint32_t height{HEIGHT};
	sf::Color color {COLOR};

public:
    void start();

public:
	~MainWindow();
	
public:
	void setBounds(const std::uint32_t& w , const std::uint32_t& h);
	void setColor(const sf::Color& colr);
	std::uint32_t getWidth();
	std::uint32_t getHeight();

};


#endif