#include "Engine/Graphics/Graphics.h"

int main()
{
    Engine::Graphics::Create();
    
    Engine::Graphics::Color white = { 255, 255, 255, 255 };
    Engine::Graphics::Color red = { 255, 0, 0, 255 };
    
    Engine::Graphics::Shape shape = Engine::Graphics::CreateRectangle(100.0f, 100.0f);
    shape.transform.position.x = Engine::Window::GetWidth() / 2.0f;
    shape.transform.position.y = Engine::Window::GetHeight() / 2.0f;
    shape.fillColor = white;
    shape.outlineColor = red;
    shape.outlineThickness = 10.0f;
    
    while(Engine::Window::IsOpen())
    {
        Engine::Graphics::Clear();
        Engine::Graphics::Draw(shape);
        Engine::Graphics::Update();
    }
    
    Engine::Graphics::Destroy();
    
    return 0;
}