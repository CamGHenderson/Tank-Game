#include "Graphics.h"
#include <SFML/Graphics.hpp>

#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720

namespace GraphicsData
{
    sf::RenderWindow window;
}

void Engine::Graphics::Create()
{
    GraphicsData::window.create(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), "");
}

void Engine::Graphics::Draw(const Shape& shape)
{
    sf::ConvexShape polygon;
    polygon.setPointCount(shape.vertices.size());
    for(uint16_t i = 0; i < shape.vertices.size(); i++)
        polygon.setPoint(i, sf::Vector2f(shape.vertices[i].x, shape.vertices[i].y));
    polygon.setFillColor(sf::Color(shape.fillColor.r, shape.fillColor.g, shape.fillColor.b, shape.fillColor.a));
    polygon.setOutlineColor(sf::Color(shape.outlineColor.r, shape.outlineColor.g, shape.outlineColor.b, shape.outlineColor.a));
    polygon.setOutlineThickness(shape.outlineThickness);
    
    polygon.setOrigin(sf::Vector2f(shape.transform.origin.x, shape.transform.origin.y));
    polygon.setPosition(sf::Vector2f(shape.transform.position.x, shape.transform.position.y));
    polygon.setScale(sf::Vector2f(shape.transform.scale.x, shape.transform.scale.y));
    polygon.setRotation(shape.transform.rotation);
    GraphicsData::window.draw(polygon);
}

void Engine::Graphics::Clear()
{
    GraphicsData::window.clear(sf::Color::Black);
}

void Engine::Graphics::Update()
{
    GraphicsData::window.display();
    
    sf::Event event;
    while(GraphicsData::window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
            {
                GraphicsData::window.close();
            }
        }
    }
}

void Engine::Graphics::Destroy()
{
    
}

bool Engine::Window::IsOpen()
{
    return GraphicsData::window.isOpen();
}

uint16_t Engine::Window::GetWidth()
{
    return GraphicsData::window.getSize().x;
}

uint16_t Engine::Window::GetHeight()
{
    return GraphicsData::window.getSize().y;
}