#ifndef B8_TOKENS_HPP
#define B8_TOKENS_HPP

#include <string>

struct token_t
{
  enum type_t
  {
    WORD,
    PUNCT,
    BLANK,
    DASH,
    NUMBER,
    INVALID
  };
  std::string str_;
  type_t type_;

};
#endif //B8_TOKENS_HPP
