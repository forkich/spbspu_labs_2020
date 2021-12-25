#include "triangle.hpp"

Triangle::Triangle(Point &point) : Shape(point)
{}

std::ostream &Triangle::draw(std::ostream &out) const
{
  out << "TRIANGLE " << centre_ << '\n';
  return out;
};


