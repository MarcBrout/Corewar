/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/parser
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 15:41:48 2016
** Last update Fri Mar 11 13:59:35 2016 
*/

#include "asm.h"
#include <string.h>

int	lexer(t_header *header, t_instruc *instruc, char *str)
{
  int	fd;
  char	*file;
  int	n;

  if ((fd = open(str, O_RDONLY)) == -1)
    return (-1);
  while ((file = get_next_line(fd)) != NULL && strlen(file) == 0);
  if (check_name(header, file) == -1)
    return (-1);
  while ((file = get_next_line(fd)) != NULL && strlen(file) == 0);
  if ((n = check_comment(header, file)) == -1)
    return (-1);
  check_instructions(instruc);
  return (0);
}
