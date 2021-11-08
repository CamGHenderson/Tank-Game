#include "Texture.h"
#include "GraphicsData.h"
#include <iostream>

Engine::Graphics::Texture Engine::Graphics::LoadTexture(const std::string& path)
{
    Texture texture;
    texture.id = Engine::Graphics::GetCurrentTextureID();
    Engine::Graphics::AddTexture();
    if(!Engine::Graphics::GetTexture(texture.id).loadFromFile(path))
    {
        // TODO Create universal error handling
        exit(0);
    }
    
    texture.width = Engine::Graphics::GetTexture(texture.id).getSize().x;
    texture.height = Engine::Graphics::GetTexture(texture.id).getSize().y;
    
    return texture;
}