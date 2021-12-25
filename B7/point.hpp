#ifndef B7_POINT_HPP
#define B7_POINT_HPP

#include <iostream>

struct Point
{
  int x;
  int y;
};

std::istream& operator >> (std::istream& in, Point& point);
std::ostream& operator << (std::ostream& out, const Point& point);

#endif //B7_POINT_HPP
