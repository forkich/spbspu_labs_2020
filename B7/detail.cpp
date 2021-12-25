#ifndef B7_DETAIL_CPP
#define B7_DETAIL_CPP

#include <iostream>

std::istream& blank(std::istream& in)
{
  if(in.peek() == '\n')
  {
    in.clear();
    in.setstate(std::ios_base::failbit);
    return in;
  }

  while(isspace(in.peek()))
  {
    in.ignore(1);
    if(in.peek() == '\n')
    {
      in.clear();
      in.setstate(std::ios_base::failbit);
      return in;
    }
  }
  return in;
}

std::istream& spaces(std::istream& in)
{
  while (isspace(in.peek()) && in.peek() != '\n')
  {
    in.ignore(1);
  }
  return in;
}

#endif //B7_DETAIL_CPP
