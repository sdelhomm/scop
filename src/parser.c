#include "../includes/scop.h"

int get_obj_sizes(int fd, t_obj_sizes *objlen)
{
  char *line;
  int ret;

  while ((ret = get_next_line(fd, &line)) > 0)
  {
    if (line[0] == 'v')
      objlen->v++;
    else if (line[0] == 'v' && line[1] == 't')
      objlen->vt++;
    else if (line[0] == 'v' && line[1] == 'n')
      objlen->vn++;
    else if (line[0] == 'f')
      objlen->f++;
  }

  if (ret < 0)
    return (0);
  return (1);
}

int parse_obj(char *file)
{
  int fd = open(file, O_RDONLY);
  t_obj_sizes objlen;

  objlen.v = 0;
  objlen.vt = 0;
  objlen.vn = 0;
  objlen.f = 0;

  if (!get_obj_sizes(fd, &objlen))
    fatal_error("Failed to read the file.");

  //!\\ ...
  printf("v = %zu / vt = %zu / vn = %zu / f = %zu\n", objlen.v, objlen.vt, objlen.vn, objlen.f);

  return (1);
}

int parse_file(char *file)
{
  char *ext = strrchr(file, '.');
  if (ext != NULL && strcmp(ext, ".obj") == 0)
    return (parse_obj(file));
  else if (ext != NULL && strcmp(ext, ".mtl") == 0)
    return (-1);
  return (-1);
}
