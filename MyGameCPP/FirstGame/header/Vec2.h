#include <iostream>
#include <SDL2/SDL.h>

#ifndef VEC2_H
#define VEC2_H

class Vec2{
private:
    
public:
    float x, y;
    
    Vec2();
    
    Vec2(float x, float y);

    Vec2 operator+(Vec2 const& rhs);

    Vec2& operator+=(Vec2 const& rhs);

    Vec2 operator*(float rhs);

    
};
#endif