#include "circle.hpp"

Circle::Circle(Point &pos) : Shape(pos)
{}

std::ostream &Circle::draw(std::ostream &out) const
{
  out << "CIRCLE " << centre_ << '\n';
  return out;
};
