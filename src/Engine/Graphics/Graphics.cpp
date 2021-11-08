#include "Graphics.h"
#include "GraphicsData.h"

#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720

namespace GraphicsData
{
    sf::RenderWindow window;
    sf::Clock deltaClock;
    float deltaTime;
    bool started = false;
}

void Engine::Graphics::Create()
{
    GraphicsData::window.create(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), "");
}

void SetTransform(sf::Transformable& transformable, const Engine::Transform& transform)
{
    transformable.setOrigin(sf::Vector2f(transform.origin.x, transform.origin.y));
    transformable.setPosition(sf::Vector2f(transform.position.x, transform.position.y));
    transformable.setScale(sf::Vector2f(transform.scale.x, transform.scale.y));
    transformable.setRotation(transform.rotation);
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
    SetTransform(polygon, shape.transform);
    GraphicsData::window.draw(polygon);
}

void Engine::Graphics::Draw(const Sprite& sprite)
{
    sf::Sprite s(Engine::Graphics::GetTexture(sprite.texture.id));
    SetTransform(s, sprite.transform);
    GraphicsData::window.draw(s);
}

float Engine::Graphics::GetDeltaTime()
{
    return GraphicsData::deltaTime;
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
    
    if(!GraphicsData::started)
    {
        GraphicsData::deltaTime = 0.0f;
        GraphicsData::deltaClock.restart();
        GraphicsData::started = true;
    }
    else
        GraphicsData::deltaTime = GraphicsData::deltaClock.restart().asSeconds();
}

void Engine::Graphics::Destroy()
{
    for(uint16_t i = 0; i < Engine::Graphics::GetCurrentTextureID(); i++)
        Engine::Graphics::DeleteTexture(i);
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