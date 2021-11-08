#pragma once
#include "../pch.h"
#include "Color.h"
#include "Transform.h"
#include "Shape.h"
#include "Sprite.h"

namespace Engine
{
    namespace Graphics
    {
        void Create();
        void Draw(const Shape& shape);
        void Draw(const Sprite& sprite);
        float GetDeltaTime();
        void Clear();
        void Update();
        void Destroy();
    }
    
    namespace Window
    {
        bool IsOpen();
        uint16_t GetWidth();
        uint16_t GetHeight();
        const std::string& GetTitle();
    }
}