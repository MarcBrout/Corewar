/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/parser
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 15:41:48 2016
** Last update Thu Mar 10 18:07:15 2016 
*/

#include "asm.h"
#include <string.h>

int	check_file(t_header *header, t_instruc *instruc, char *str)
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

int		main(int ac, char **av)
{
  t_header	header;
  t_instruc	instruc;

  if (ac != 2)
    {
      write(2, "Wrong arguments\n", 16);
      return (-1);
    }
  check_file(&header, &instruc, av[1]);
}
