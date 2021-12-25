#include "in_iterator.hpp"

#include <iostream>
#include <locale>

const int MAX_WORD_LENGTH = 20;
const int MIN_WORD_LENGTH = 20;

tokenIterator::tokenIterator::tokenIterator(std::istream &in):
  istream_(&in),
  token_(token_t{"", token_t::INVALID}),
  state_(true),
  locale_(istream_->getloc())
{
  read_token();
}


tokenIterator::tokenIterator():
  istream_(nullptr),
  token_(token_t{"",token_t::INVALID}),
  state_(false),
  locale_()

{}

bool tokenIterator::operator!=(const tokenIterator &other) const
{
  return !(this->operator==(other));
}

bool tokenIterator::operator==(const tokenIterator &other) const
{
  return state_ == other.state_ && (!state_ || istream_ == other.istream_);
}

const token_t &tokenIterator::operator*() const
{
  return token_;
}

const token_t *tokenIterator::operator->() const
{
  return &token_;
}

tokenIterator &tokenIterator::operator++()
{
  read_token();
  return *this;
}

tokenIterator tokenIterator::operator++(int)
{
  auto temp = this;
  read_token();
  return *temp;
}

void tokenIterator::read_token()
{
  char c = (*(istream_) >> std::ws).get();
  char next_c = istream_->peek();

  if(istream_->fail())
  {
    state_ = false;
    return;
  }
  else if(isalpha(c, locale_))
  {
    istream_->unget();
    read_word();
  }
  else if(c == '-')
  {
    if (next_c == '-')
    {
      istream_->unget();
      read_dash();
    }
    else
    {
      istream_->unget();
      read_num();
    }

  }
  else if((isdigit(c, locale_)) || (c == '+'))
  {
    istream_->unget();
    read_num();
  }
  else if(ispunct(c, locale_))
  {
    istream_->unget();
    read_punct();
  }
  else
  {
    throw std::invalid_argument(" wrong expression! \n");
  }
}

void tokenIterator::read_word()
{
  token_t token{ "",token_t::WORD,};

  while ((std::isalpha<char>(istream_->peek(), std::locale())) || (istream_->peek() == '-'))
  {
    char ch = istream_->get();
    if ((ch == '-') && (istream_->peek() == '-'))
    {
      istream_->unget();
      break;
    }
    token.str_.push_back(ch);
  }

  if (token.str_.size() > MAX_WORD_LENGTH)
  {
    throw std::invalid_argument(" length of word must be less than 20! \n");
  }

  token_.str_ = token.str_;
  token_.type_ = token.type_;

}

void tokenIterator::read_dash()
{
  if (token_.type_ == token_t::INVALID)
  {
    throw std::invalid_argument(" line can not start with a dash! \n");
  }

  if (token_.type_ == token_t::DASH || (token_.type_ == token_t::PUNCT   && (token_.str_ != ",")))
  {
    throw std::invalid_argument(" wrong placement of dash! \n");
  }

  token_t token{ "",token_t::DASH};
  while (istream_->peek() == '-')
  {
    token.str_.push_back(istream_->get());
  }

  if (token.str_.size() != 3)
  {
    throw std::invalid_argument(" wrong dash number!");
  }

  token_.str_ = token.str_;
  token_.type_ = token.type_;
}

void tokenIterator::read_num()
{
  token_t token{ "",token_t::NUMBER};
  const char decimalPoint = std::use_facet < std::numpunct < char >> (std::locale()).decimal_point();
  bool wasDecimal = false;

  char ch = istream_->get();
  token.str_.push_back(ch);

  while ((std::isdigit<char>(istream_->peek(), std::locale())) || ((istream_->peek() == decimalPoint)))
  {
    ch = istream_->get();
    if (ch == decimalPoint)
    {
      if (wasDecimal)
      {
        throw std::invalid_argument(" wrong number! \n");
      }
      wasDecimal = true;
    }
    token.str_.push_back(ch);
  }

  if (token.str_.size() > MAX_WORD_LENGTH)
  {
    throw std::invalid_argument(" length of number must be less than 20! \n");
  }

  token_.str_ = token.str_;
  token_.type_ = token.type_;

}

void tokenIterator::read_punct()
{
  if (token_.type_ == token_t::INVALID)
  {
    throw std::invalid_argument(" line can not start with a mark! \n");
  }

  if (token_.type_ == token_t::PUNCT || token_.type_ == token_t::DASH)
  {
    throw std::invalid_argument(" wrong placement of mark! \n");
  }

  token_t token{"",token_t::PUNCT};

  token.str_.push_back(istream_->get());
  token_.str_ = token.str_;
  token_.type_ = token.type_;

}

