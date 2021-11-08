#pragma once
#include "Texture.h"
#include "Transform.h"

namespace Engine
{
    namespace Graphics
    {
        struct Sprite
        {
            Texture texture;
            Transform transform;
        };
    }
}