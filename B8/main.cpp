#include <iostream>
#include <cstring>

void task_1(size_t line_width);

int main(int argc, char *argv[])
{
  try
  {
    if ((argc != 1) && (argc != 3))
    {
      throw std::invalid_argument(" wrong number of arguments! \n");
    }

    size_t line_width = 40;

    if (argc == 3)
    {
      if (strcmp(argv[1], "--line-width") != 0)
      {
        throw std::invalid_argument(" wrong number of arguments! \n");
      }

      line_width = std::stoi(argv[2]);

      if (line_width < 25)
      {
        throw std::invalid_argument(" length of line must be more than 25 ! \n");
      }
    }

    task_1(line_width);
  }
  catch (const std::exception &exception)
  {
    std::cerr << exception.what() << std::endl;
    return 1;
  }

  return 0;
}
