#ifndef B7_SHAPE_HPP
#define B7_SHAPE_HPP

#include <iostream>
#include <memory>
#include "point.hpp"

class Shape
{
public:
  using shape_pointer = std::shared_ptr<Shape>;

  Shape(Point& pos);
  virtual ~Shape() = default;
  virtual std::ostream& draw(std::ostream& out) const = 0;
  bool isMoreLeft(const Shape& shape);
  bool isMoreUpper(const Shape& shape);

protected:
  Point centre_;
};

std::istream& operator >> (std::istream& in, std::shared_ptr<Shape>& shape);

#endif //B7_SHAPE_HPP
