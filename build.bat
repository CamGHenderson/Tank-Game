@echo off

g++ src/app.cpp src/Engine/Graphics/Graphics.cpp src/Engine/Graphics/GraphicsData.cpp src/Engine/Graphics/Texture.cpp src/Engine/Graphics/Shape.cpp src/Engine/Graphics/Sprite.cpp -o bin/app -I C:\Users\Light\Desktop\4coder\Libraries\include -L C:\Users\Light\Desktop\4coder\Libraries\lib -mwindows -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lopengl32