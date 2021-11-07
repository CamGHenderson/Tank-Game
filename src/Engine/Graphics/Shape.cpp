#include "Shape.h"

Engine::Graphics::Shape Engine::Graphics::CreateRectangle(float width, float height)
{
    Engine::Transform transform;
    transform.origin.x = width / 2.0f;
    transform.origin.y = height / 2.0f;
    transform.position.x = 0.0f;
    transform.position.y = 0.0f;
    transform.scale.x = 1.0f;
    transform.scale.y = 1.0f;
    transform.rotation = 0.0f;
    
    Engine::Graphics::Shape shape;
    shape.transform = transform;
    shape.vertices.push_back({ 0.0f, 0.0f });
    shape.vertices.push_back({ width, 0.0f });
    shape.vertices.push_back({ width, height });
    shape.vertices.push_back({ 0.0f, height });
    
    return shape;
}