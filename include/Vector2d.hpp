#pragma once
#include<cmath>

struct Vector2d {
    float x, y;

    Vector2d(float _x = 0.0f, float _y = 0.0f);

    Vector2d operator+(const Vector2d& other) const;
    Vector2d operator-(const Vector2d& other) const;
    Vector2d operator*(float scalar) const;

    float length() const;
    Vector2d normalized() const;

};

