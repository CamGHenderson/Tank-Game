#include "Sprite.h"

Engine::Graphics::Sprite Engine::Graphics::CreateSprite(const std::string& path)
{
    Engine::Graphics::Sprite sprite;
    sprite.texture = Engine::Graphics::LoadTexture(path);
    return sprite;
}

Engine::Graphics::Sprite Engine::Graphics::CreateSprite(const Texture& texture)
{
    Engine::Graphics::Sprite sprite;
    sprite.texture = texture;
    return sprite;
}