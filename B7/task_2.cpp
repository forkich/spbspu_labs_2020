#include <iterator>
#include <iostream>
#include <algorithm>
#include <functional>
#include <list>
#include "shape.hpp"

void print_list(std::list<Shape::shape_pointer>& list)
{
  std::for_each(list.begin(), list.end(), [](Shape::shape_pointer& ptr){ ptr->draw(std::cout); });
}

void task_2()
{
  std::list<std::shared_ptr<Shape>> list(std::istream_iterator<std::shared_ptr<Shape>>(std::cin),
                                             std::istream_iterator<std::shared_ptr<Shape>>{});

  if(std::cin.fail() && !std::cin.eof())
  {
    throw std::ios_base::failure(" fail in reading stream ! \n");
  }

  std::cout << "Original:" << '\n';
  print_list(list);
  list.sort([](const Shape::shape_pointer& lhs, const Shape::shape_pointer& rhs){ return lhs->isMoreLeft(*rhs); });
  std::cout << "Left-Right:" << '\n';
  print_list(list);

  std::cout << "Right-Left:" << '\n';
  list.reverse();
  print_list(list);

  list.sort([](const Shape::shape_pointer & lhs, const Shape::shape_pointer & rhs){ return lhs->isMoreUpper(*rhs); });
  std::cout << "Top-Bottom:" << '\n';
  print_list(list);

  std::cout << "Bottom-Top:" << '\n';
  list.reverse();
  print_list(list);

}
