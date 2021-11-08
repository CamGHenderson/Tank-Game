#include "GraphicsData.h"

namespace GraphicsData
{
    std::map<uint16_t, sf::Texture*> textures;
    uint16_t idCount = 0;
}

uint16_t Engine::Graphics::GetCurrentTextureID()
{
    return GraphicsData::idCount;
}

void Engine::Graphics::AddTexture()
{
    GraphicsData::textures[GraphicsData::idCount] = new sf::Texture();
    GraphicsData::idCount++;
}

void Engine::Graphics::DeleteTexture(uint16_t id)
{
    sf::Texture* texture = &Engine::Graphics::GetTexture(id);
    GraphicsData::textures.erase(id);
    delete texture;
}

sf::Texture& Engine::Graphics::GetTexture(uint16_t id)
{
    return *GraphicsData::textures[id];
}