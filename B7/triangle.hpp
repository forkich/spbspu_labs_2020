#ifndef B7_TRIANGLE_HPP
#define B7_TRIANGLE_HPP

#include "shape.hpp"
#include "point.hpp"

class Triangle : public Shape
{
public:
  Triangle(Point& point);
  std::ostream & draw(std::ostream &out) const override;
};

#endif //B7_TRIANGLE_HPP
