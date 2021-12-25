#ifndef B8_FORMAT_FUNCTOR_HPP
#define B8_FORMAT_FUNCTOR_HPP

#include <iostream>
#include <string>
#include "tokens.hpp"

class formatFunctor
{
public:
  formatFunctor(size_t line_width, std::ostream& out);
  ~formatFunctor();
  void operator()(const token_t & token);

private:
  std::ostream& output_;
  const size_t line_width_;
  std::string str_;
};



#endif //B8_FORMAT_FUNCTOR_HPP
