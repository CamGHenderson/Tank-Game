#pragma once
#include "../pch.h"

namespace Engine
{
    namespace Graphics 
    {
        struct Texture
        {
            uint16_t id;
            uint16_t width;
            uint16_t height;
        };
        
        Texture LoadTexture(const std::string& path);
        void DeleteTexture(const Texture& texture);
    }
}