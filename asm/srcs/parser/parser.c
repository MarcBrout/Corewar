/*
** parser.c for PARSE in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar 10 15:08:25 2016 bougon_p
** Last update Fri Mar 11 15:16:23 2016 bougon_p
*/

#include "asm.h"
#include <string.h>
#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

int	sizeofextens(char *name)
{
  int	i;
  int	p;

  p = 0;
  i = my_strlen(name);
  while (name[--i] != '.' && i >= 0)
    p++;
  return (p + 1);
}

int	create_file(t_header *head, char *name)
{
  int	fd;
  char	*new_name;

  if ((new_name = malloc(sizeof(char) * my_strlen(name) + 1)) == NULL)
    return (1);
  set_line_null(new_name, my_strlen(name));
  strncpy(new_name, name, my_strlen(name) - sizeofextens(name));
  if ((new_name = realloc
       (new_name, my_strlen(name) - sizeofextens(name) + 5)) == NULL)
    return (my_putstr_err("asm : error: malloc error\n"), 1);
  strcat(new_name, ".cor");
  if ((fd = open(new_name, O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    return (my_putstr_err("asm : error: open error\n"), 1);
  free(new_name);
  return (fd);
}

int	convert_bigend_to_littleend_int(int var)
{
  int	tmp;

  tmp = 0;
  tmp = (var & 0xFF000000) >> 24;
  tmp |= ((var & 0x00FF0000) >> 8);
  tmp |= (var & 0x0000FF00) << 8;
  tmp |= ((var & 0x000000FF) << 24);
  return (tmp);
}

int	write_magic(int fd)
{
  int	magic;

  magic = COREWAR_EXEC_MAGIC;
  magic = convert_bigend_to_littleend_int(magic);
  if ((write(fd, &magic, sizeof(magic)) == -1) == -1)
    return (-1);
  return (0);
}

int	write_name()
{
  return (0);
}

int	write_prog_size()
{
  return (0);
}

int	write_comment()
{
  return (0);
}


int	write_header(char *name, int fd, t_header *head)
{
  write_magic(fd);
  write_name();
  write_prog_size();
  write_comment();
}

int	parser(char *name, t_header *head)
{
  int	fd;

  if ((fd = create_file(head, name)) == 1)
    return (1);
  write_header(name, fd, head);
  close(fd);
  return (0);
}
