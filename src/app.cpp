#include "Engine/Graphics/Graphics.h"

struct Tank
{
    Engine::Graphics::Sprite body;
    Engine::Graphics::Sprite turret;
};

void DrawTank(Tank& tank)
{
    Engine::Graphics::Draw(tank.body);
    //tank.turret.position
    Engine::Graphics::Draw(tank.turret);
}

int main()
{
    Engine::Graphics::Create();
    
    Engine::Vec2 center = { Engine::Window::GetWidth() / 2.0f, Engine::Window::GetHeight() / 2.0f };
    
    Tank tank;
    tank.body = Engine::Graphics::CreateSprite("res/Textures/TankBody.png");
    tank.turret = Engine::Graphics::CreateSprite("res/Textures/TankTurret.png");
    
    while(Engine::Window::IsOpen())
    {
        Engine::Graphics::Clear();
        DrawTank(tank);
        Engine::Graphics::Update();
    }
    
    Engine::Graphics::Destroy();
    
    return 0;
}