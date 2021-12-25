#include "point.hpp"
#include "detail.hpp"

std::istream& operator >> (std::istream& in, Point& point)
{
  if(in.peek() == std::char_traits<char>::eof())
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  int pos;
  in >> blank;
  if(in.peek() != '(')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  in.ignore(1);
  in >> blank >> pos >> blank;
  if(in.peek() != ';')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  in.ignore(1);
  point.x = pos;
  in >> blank >> pos >> blank;
  if(in.peek() != ')')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  in.ignore(1);
  point.y = pos;
  return in;
}

std::ostream& operator << (std::ostream& out, const Point& point)
{
  out << "(" << point.x << ";" << point.y << ")";
  return out;
}
