#include "../includes/scop.h"

void init_scop(t_param *p)
{
  glfwSetErrorCallback(error_callback);
  if (!glfwInit())
    fatal_error("GLFW initialization failed.");

  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
  if (!(p->win = glfwCreateWindow(W_WIDTH, W_HEIGHT, "scop", NULL, NULL)))
    fatal_error("Failed to create window or OpenGL context.");

  glfwMakeContextCurrent(p->win);
  glfwSwapInterval(1);/* vsync */
}
