#include "../includes/scop.h"

void fatal_error(char *error)
{
  printf("%s\n", error);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
  if (argc != 2)
    fatal_error("Please give one file as argument.");

  if (parse_file(argv[1]) < 0)
    fatal_error("The file needs to be in '.obj' extension.");
  return (0);
}
