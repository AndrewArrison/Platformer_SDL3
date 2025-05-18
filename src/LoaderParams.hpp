#pragma once
#include <string>
#include <SDL3/SDL.h>

class LoaderParams
{
public:
    LoaderParams(float x, float y, float width, float height, std::string textureID)
    : m_x(x), m_y(y), m_width(width), m_height(height), m_textureID(textureID){}
    float getX() const { return m_x; }
    float getY() const { return m_y; }
    float getWidth() const { return m_width; }
    float getHeight() const { return m_height; }
    std::string getTextureID() const { return m_textureID; }

private:
    float m_x;
    float m_y;

    float m_width;
    float m_height;
    
    std::string m_textureID;
};