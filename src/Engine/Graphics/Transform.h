#pragma once

namespace Engine
{
    struct Vec2
    {
        float x = 0.0f;
        float y = 0.0f;
    };
    
    struct Transform
    {
        Vec2 origin = { 0.0f, 0.0f};
        Vec2 position = { 0.0f, 0.0f };
        Vec2 scale = { 1.0f, 1.0f };
        float rotation = 0.0f;
    };
}