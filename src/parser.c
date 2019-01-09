#include "../includes/scop.h"

int get_obj_sizes(int fd, t_obj_sizes *objlen)
{
  char *line;
  int ret;

  while ((ret = get_next_line(fd, &line)) > 0)
  {
    if (line[0] == 'v' && line[1] == ' ')
      objlen->v++;
    else if (line[0] == 'v' && line[1] == 't' && line[2] == ' ')
      objlen->vt++;
    else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ')
      objlen->vn++;
    else if (line[0] == 'f' && line[1] == ' ')
      objlen->f++;
  }

  if (ret < 0)
    return (0);
  return (1);
}

void parse_obj(char *file)
{
  int fd = open(file, O_RDONLY);
  t_obj_sizes objlen;
  //t_obj_values objval;

  objlen.v = 0;
  objlen.vt = 0;
  objlen.vn = 0;
  objlen.f = 0;

  if (!get_obj_sizes(fd, &objlen))
    fatal_error("Failed to read the file.");

  // objval.v = malloc(objlen.v * sizeof(objval.v));
  // objval.vt = malloc(objlen.vt * sizeof(objval.vt));
  // objval.vn = malloc(objlen.vn * sizeof(objval.vn));
  // objval.f = malloc(objlen.f * sizeof(objval.vf));
  //
  // if (objval.v == NULL || objval.vt == NULL || objval.vn == NULL
  //   || objval.vf == NULL)
  //   fatal_error("Failed to allocate memory.");
}

void parse_file(char *file)
{
  char *ext = strrchr(file, '.');
  if (ext == NULL || strcmp(ext, ".obj") != 0)
    fatal_error("The file needs to be in '.obj' extension.");

  parse_obj(file);
}
