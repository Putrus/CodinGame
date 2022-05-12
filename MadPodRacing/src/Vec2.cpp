#include "../include/Vec2.h"

Vec2::Vec2() : x(0), y(0) {
}

Vec2::Vec2(int x, int y) : x(x), y(y) {
}

double Vec2::length() const {
   return std::sqrt(x * x + y * y);
}

double Vec2::dist(Vec2& v) const {
   return std::sqrt((v.x - this->x) * (v.x - this->x) + (v.y - this->y) * (v.y - this->y));
}

Vec2& Vec2::operator++() {
   ++x;
   ++y;
   return *this;
}

Vec2 Vec2::operator++(int) {
   Vec2 v = *this;
   ++* this;
   return v;
}

Vec2& Vec2::operator--() {
   --x;
   --y;
   return *this;
}

Vec2 Vec2::operator--(int) {
   Vec2 v = *this;
   --* this;
   return v;
}

Vec2 Vec2::operator+(const int& n) {
   return Vec2(this->x + n, this->y + n);
}

Vec2 Vec2::operator+(const Vec2& v) {
   return Vec2(this->x + v.x, this->y + v.y);
}

Vec2 Vec2::operator-(const int& n) {
   return Vec2(this->x - n, this->y - n);
}

Vec2 Vec2::operator-(const Vec2& v) {
   return Vec2(this->x - v.x, this->y - v.y);
}

std::ostream& operator<<(std::ostream& os, const Vec2& v) {
   os << v.x << ' ' << v.y;
   return os;
}

std::istream& operator>>(std::istream& is, Vec2& v) {
   is >> v.x >> v.y;
   return is;
}

bool operator==(const Vec2& lhs, const Vec2& rhs) {
   return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool operator!=(const Vec2& lhs, const Vec2& rhs) {
   return lhs.x != rhs.x || lhs.y != rhs.y;
}