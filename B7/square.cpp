#include "square.hpp"

Square::Square(Point &point) : Shape(point)
{}

std::ostream &Square::draw(std::ostream &out) const
{
  out << "SQUARE " << centre_ << '\n';
  return out;
};

