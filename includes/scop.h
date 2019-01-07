#ifndef SCOP_H
# define SCOP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef struct  s_obj_sizes
{
  size_t v;
  size_t vt;
  size_t vn;
  size_t f;
}               t_obj_sizes;

int   parse_file(char *file);
void  fatal_error(char *error);

#endif
