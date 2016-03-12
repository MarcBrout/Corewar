/*
** parser.c for PARSE in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar 10 15:08:25 2016 bougon_p
** Last update Sat Mar 12 16:04:06 2016 bougon_p
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

int	write_magic(int fd)
{
  int	magic;

  magic = COREWAR_EXEC_MAGIC;
  magic = convert_bigend_to_littleend_int(magic);
  if ((write(fd, &magic, sizeof(magic)) == -1) == -1)
    return (-1);
  return (0);
}

int	write_name(t_header *head, int fd)
{
  int	size;
  int	i;

  i = -1;
  size = 129;
  write(fd, &head->prog_name[0], my_strlen(&head->prog_name[0]));
  size -= my_strlen(&head->prog_name[0]);
  while (++i < size + 3)
    write(fd, "\0", 1);
  return (0);
}

int	write_prog_size(t_header *head, int fd)
{
  int	prog_size;

  prog_size = head->prog_size;
  prog_size = convert_bigend_to_littleend_int(prog_size);
  write(fd, &prog_size, sizeof(prog_size));
  return (0);
}

int	write_comment(t_header *head, int fd)
{
  int	size;
  int	i;

  size = 2049;
  i = -1;
  size -= my_strlen(&head->comment[0]);
  write(fd, &head->comment[0], my_strlen(&head->comment[0]));
  while (++i < size + 3)
    write(fd, "\0", 1);
  return (0);
}


int	write_header(char *name, int fd, t_header *head)
{
  write_magic(fd);
  write_name(head, fd);
  write_prog_size(head, fd);
  write_comment(head, fd);
}

int	parser(char *name, t_header *head)
{
  int	fd;

  if ((fd = create_file(head, name)) == 1)
    return (1);
  head->prog_size = 22;
  write_header(name, fd, head);
  close(fd);
  return (0);
}
