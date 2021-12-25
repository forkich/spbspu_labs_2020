#ifndef B7_CIRCLE_HPP
#define B7_CIRCLE_HPP

#include "shape.hpp"
#include "point.hpp"
class Circle: public Shape
{
public:
  Circle(Point& pos);
  std::ostream& draw(std::ostream& out) const override;

};

#endif //B7_CIRCLE_HPP
