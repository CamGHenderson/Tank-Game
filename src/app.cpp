#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

sf::RenderWindow window;

void handleEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
            {
                window.close();
            }
        }
    }
}

int main()
{
    window.create(sf::VideoMode(800, 600), "Tank Game");
    
    Game game("Send Help");

    while(window.isOpen())
    {
        handleEvents();
        
        window.clear(sf::Color::Black);
        window.display();
    }
    
    return 0;
}