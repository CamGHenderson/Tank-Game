#pragma once

namespace Engine
{
    struct Vec2
    {
        float x;
        float y;
    };
    
    struct Transform
    {
        Vec2 origin;
        Vec2 position;
        Vec2 scale;
        float rotation;
    };
}