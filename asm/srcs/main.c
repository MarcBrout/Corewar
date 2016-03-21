/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 13:57:07 2016
** Last update Mon Mar 21 19:43:41 2016 bougon_p
*/

#include "asm.h"

int		main(int ac, char **av)
{
  t_header	header;
  t_instruc	instruc;

  if (ac == 1)
    {
      write(2, "Wrong arguments\n", 16);
      return (-1);
    }
  if (lexer(&header, &instruc, av[1]) == -1)
    return (-1);
  print_list(&instruc);
  parser(av[1], &header, &instruc);
  free_parser(&header, &instruc);
  return (0);
}
