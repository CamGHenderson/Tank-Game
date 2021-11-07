#pragma once
#include "../pch.h"
#include "Transform.h"
#include "Color.h"

namespace Engine
{
    namespace Graphics
    {
        struct Shape
        {
            Transform transform;
            std::vector<Engine::Vec2> vertices;
            Engine::Graphics::Color fillColor;
            Engine::Graphics::Color outlineColor;
            float outlineThickness;
        };
        
        Shape CreateRectangle(float width, float height);
    }
}