#pragma once

#include <cmath>
#include <iostream>

class Vec2 {
public:
   //coordinates
   int x;
   int y;

   Vec2();
   Vec2(int x, int y);

   //distance from (0,0) point
   double length() const;

   //distance between this and v vectors
   double dist(Vec2& v) const;

   //prefix increment
   Vec2& operator++();

   //postfix increment
   Vec2 operator++(int);

   //prefix decrement
   Vec2& operator--();

   //postfix decrement
   Vec2 operator--(int);

   //add int
   Vec2 operator+(const int& n);

   //add vec2
   Vec2 operator+(const Vec2& v);

   //subtract int
   Vec2 operator-(const int& n);

   //subtract vec2
   Vec2 operator-(const Vec2& v);

   friend std::ostream& operator<<(std::ostream& os, const Vec2& v);
   friend std::istream& operator>>(std::istream& is, Vec2& v);
   friend bool operator==(const Vec2& lhs, const Vec2& rhs);
   friend bool operator!=(const Vec2& lhs, const Vec2& rhs);
};
