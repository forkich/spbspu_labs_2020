#include "format_functor.hpp"

formatFunctor::formatFunctor(size_t lineWidth, std::ostream &out) :
        output_(out),
        line_width_(lineWidth),
        str_()
{}

formatFunctor::~formatFunctor()
{
  if (!str_.empty())
  {
    output_ << str_ << "\n";
  }
}

void formatFunctor::operator()(const token_t &token)
{
  if (token.type_ == token_t::WORD || token.type_ == token_t::NUMBER)
  {
    if ((str_.size() + token.str_.size() + 1) > line_width_)
    {
      output_ << str_ << '\n';
      str_.clear();
    }
    else if (!str_.empty())
    {
      str_ += " ";
    }

    str_ += token.str_;
  }
  else
  {
    if ((token.type_ == token_t::DASH && ((str_.size() + 4) > line_width_))
        || (((str_.size() + 1) > line_width_)))
    {
      size_t last_space = str_.find_last_of(' ');
      size_t count_of_odd_ch = str_.size() - last_space;

      std::string temp = str_.substr(last_space, count_of_odd_ch);
      str_.erase(last_space, count_of_odd_ch);
      output_ << str_ << '\n';

      str_ = temp.erase(0, 1);
    }

    if (token.type_ == token_t::DASH)
    {
      str_ += " ";
    }

    str_ += token.str_;

  }
}

