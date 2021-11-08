#include "Engine/Graphics/Graphics.h"

int main()
{
    Engine::Graphics::Create();
    
    Engine::Vec2 center = { Engine::Window::GetWidth() / 2.0f, Engine::Window::GetHeight() / 2.0f };
    
    Engine::Graphics::Sprite sprite;
    sprite.texture = Engine::Graphics::LoadTexture("res/Textures/TankBody.png");
    sprite.transform.origin = { sprite.texture.width / 2.0f, sprite.texture.height / 2.0f};
    sprite.transform.position = center;
    
    while(Engine::Window::IsOpen())
    {
        Engine::Graphics::Clear();
        Engine::Graphics::Draw(sprite);
        Engine::Graphics::Update();
    }
    
    Engine::Graphics::Destroy();
    
    return 0;
}