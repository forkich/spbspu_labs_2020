#ifndef B7_SQUARE_HPP
#define B7_SQUARE_HPP

#include "shape.hpp"
#include "point.hpp"

class Square: public Shape
{
public:
  Square(Point& point);
  std::ostream & draw(std::ostream &out) const override;
};


#endif //B7_SQUARE_HPP
