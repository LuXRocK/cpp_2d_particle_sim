#pragma once
#include <cmath>
#include <iostream>

struct Vector2d {
    float x, y;

    Vector2d(float _x = 0.0f, float _y = 0.0f);

    Vector2d operator+(const Vector2d& other) const;
    Vector2d operator-(const Vector2d& other) const;
    Vector2d operator*(float scalar) const;
    Vector2d& operator+=(const Vector2d& other);
    Vector2d& operator*=(float scalar);


    float length() const;
    Vector2d normalized() const;
    void print() const;

};

