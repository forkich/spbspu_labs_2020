#include "shape.hpp"
#include <unordered_map>
#include <functional>
#include "circle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "detail.hpp"

Shape::Shape(Point &pos):
  centre_(pos)
{}

std::istream& operator>>(std::istream& in, Shape::shape_pointer & shape)
{
  in >> std::ws;
  if (in.eof())
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }

  std::string figure;
  while ((in.peek() != '(') && (!in.eof()) && (!isspace(in.peek())))
  {
    char symbol;
    in.get(symbol);
    figure.push_back(symbol);
  }

  if (in.eof())
  {
    in.clear(std::ios_base::failbit);
    return in;
  }

  static std::unordered_map <std::string, std::function<Shape::shape_pointer(Point &)>> map = {
          {"CIRCLE",   [](Point &point)
                       { return std::make_shared<Circle>(point); }},
          {"TRIANGLE", [](Point &point)
                       { return std::make_shared<Triangle>(point); }},
          {"SQUARE",   [](Point &point)
                       { return std::make_shared<Square>(point); }}
  };

  auto iter = map.find(figure);

  if (iter == map.end())
  {
    in.clear(std::ios_base::failbit);
    return in;
  }

  Point pos;
  in >> pos >> spaces;

  if (in.fail())
  {
    return in;
  }

  Shape::shape_pointer new_shape = iter->second(pos);
  shape.swap(new_shape);

  return in;
}

bool Shape:: isMoreLeft(const Shape& shape)
{
  return centre_.x < shape.centre_.x;
}

bool Shape:: isMoreUpper(const Shape& shape)
{
  return centre_.y > shape.centre_.y;
}
