/*
** parser.c for PARSE in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar 10 15:08:25 2016 bougon_p
** Last update Tue Mar 15 18:22:41 2016 bougon_p
*/

#include "asm.h"

int	parser(char *name, t_header *head, t_instruc *instruc)
{
  int	fd;

  if ((fd = create_file(name)) == 1)
    return (1);
  head->prog_size = 22;
  if (write_header(fd, head) == 1)
    return (1);
  if (write_code(fd, instruc) == 1)
    return (1);
  close(fd);
  return (0);
}
