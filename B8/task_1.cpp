#include <iostream>
#include <algorithm>
#include <functional>
#include "in_iterator.hpp"
#include "format_functor.hpp"

void task_1(size_t line_width)
{
  formatFunctor functor(line_width, std::cout);

  std::for_each(tokenIterator(std::cin), tokenIterator(), std::ref(functor));

  if ((!std::cin.eof()) && (std::cin.fail()))
  {
    throw std::invalid_argument(" fail in out stream! \n");
  }

}

