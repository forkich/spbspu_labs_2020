#ifndef B8_IN_ITERATOR_HPP
#define B8_IN_ITERATOR_HPP

#include <iostream>
#include <memory>
#include <locale>
#include <iterator>
#include "tokens.hpp"


class tokenIterator: public std::iterator<std::input_iterator_tag, token_t>
{
public:
  tokenIterator();
  tokenIterator(std::istream&);

  bool operator!=(tokenIterator const& other) const;
  bool operator==(tokenIterator const& other) const;
  const token_t &operator*() const;
  const token_t *operator->() const;

  tokenIterator& operator++();
  tokenIterator operator++(int);

private:

  std::istream* istream_;
  token_t token_;
  bool state_;
  const std::locale locale_;

  void read_token();
  void read_word();
  void read_dash();
  void read_num();
  void read_punct();

};


#endif //B8_IN_ITERATOR_HPP
