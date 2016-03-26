/*
** create_file.c for BINARY in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar 11 15:29:29 2016 bougon_p
** Last update Sat Mar 26 18:13:20 2016 bougon_p
*/

#include "asm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	sizeofextens(char *name)
{
  int   i;
  int   p;

  p = 0;
  i = my_strlen(name);
  while (i >= 0 && name[--i] != '.')
    p++;
  if ((my_strcmp(&name[i], ".s") != 0)
      || i == -1)
    return (0);
  return (p + 1);
}

int	create_file(char *name)
{
  int   fd;
  char  *new_name;

  new_name = my_strndup(name, my_strlen(name) - sizeofextens(name));
  if ((new_name = realloc
       (new_name, my_strlen(name) - sizeofextens(name) + 5)) == NULL)
    return (malloc_fail(), 1);
  my_strcat(new_name, ".cor");
  if ((fd = open(new_name, O_WRONLY | O_CREAT | O_TRUNC,
                 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    return (1);
  free(new_name);
  return (fd);
}
