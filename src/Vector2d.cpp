#include "Vector2d.hpp"

Vector2d::Vector2d(float _x, float _y) : x(_x), y(_y) {}

Vector2d Vector2d::operator+(const Vector2d& other) const {
    return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator-(const Vector2d& other) const {
    return Vector2d(x - other.x, y - other.y);
}

Vector2d Vector2d::operator*(float scalar) const {
    return Vector2d(x * scalar, y * scalar);
}

