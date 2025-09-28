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

Vector2d& Vector2d::operator+=(const Vector2d& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2d& Vector2d::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

float Vector2d::length() const {
    return std::sqrt((x*x) + (y*y));
}

Vector2d Vector2d::normalized() const {
    float len = length();
    if(len == 0) return Vector2d(0, 0);
    return Vector2d(x/length(), y/length());
}

float Vector2d::dot(const Vector2d& other) const {
    return (x * other.x) + (y * other.y);
}

void Vector2d::print() const{
    std::cout << "x: " << x << " y: " << y << std::endl;
}

