#pragma once
#include <SFML/Graphics.hpp>
#include "../pch.h"

namespace Engine
{
    namespace Graphics
    {
        uint16_t GetCurrentTextureID();
        void AddTexture();
        void DeleteTexture(uint16_t i);
        sf::Texture& GetTexture(uint16_t id);
    }
}