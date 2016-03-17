/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 13:57:07 2016
** Last update Thu Mar 17 17:42:11 2016 bougon_p
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
  /* i = 0; */
  /* while (++i < ac) */
  /*   lexer(&header, &instruc, av[i]); */
  if (lexer(&header, &instruc, av[1]) != 0)
    return (1);
  print_list(&instruc);
  parser(av[1], &header, &instruc);
  return (0);
}
