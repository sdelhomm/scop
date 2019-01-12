#ifndef SCOP_H
# define SCOP_H

#define GLEW_STATIC

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
#include <glad/glad.h>
# include <GLFW/glfw3.h>
# include "../libft/includes/libft.h"

# define W_WIDTH 800
# define W_HEIGHT 600

typedef struct  s_param
{
  GLFWwindow* win;
}               t_param;

typedef struct  s_obj_sizes
{
  size_t v;
  size_t vt;
  size_t vn;
  size_t f;
}               t_obj_sizes;

typedef struct  s_obj_values
{
  float *v;
  float *vt;
  float *vn;
  float *f;
}               t_obj_values;

void  parse_file(char *file);
void  fatal_error(char *error);
void  init_scop(t_param *p);
void  leave_scop(t_param *p);
void  error_callback(int error, const char* description);

#endif
