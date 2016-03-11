/*
** parser.c for PARSE in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar 10 15:08:25 2016 bougon_p
** Last update Fri Mar 11 13:59:26 2016 
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

void	my_putstr_err(char *str)
{
  write(2, str, my_strlen(str));
}

int	create_file(t_header *head)
{
  int	fd;
  char	*name;

  if ((name = strdup(&head->prog_name[0])) == NULL)
    return (my_putstr_err("asm : error: malloc error\n"), 1);
  if ((name = realloc(name, my_strlen(name) + 5)) == NULL)
    return (my_putstr_err("asm : error: malloc error\n"), 1);
  name[my_strlen(name)] = 0;
  strcat(name, ".cor");
  if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    return (my_putstr_err("asm : error: open error\n"), 1);
  free(name);
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

void	write_magic(int fd)
{
  int	magic;

  magic = COREWAR_EXEC_MAGIC;
  magic = convert_bigend_to_littleend_int(magic);
  write(fd, &magic, sizeof(magic));


  /* write(fd, ptr, 4); */
}

int	parser(t_header *head)
{
  int	fd;

  if ((fd = create_file(head)) == 1)
    return (1);
  write_magic(fd);
  close(fd);
  return (0);
}
