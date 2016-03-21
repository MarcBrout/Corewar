/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 13:57:07 2016
** Last update Mon Mar 21 22:52:43 2016 marel_m
*/

#include "asm.h"

int		main(int ac, char **av)
{
  t_header	header;
  t_instruc	instruc;
  int		i;

  if (ac == 1)
    {
      write(2, "Wrong arguments\n", 16);
      return (-1);
    }
  i = 0;
  while (++i < ac)
    {
      if (lexer(&header, &instruc, av[i]) == -1)
	{
	  printf("Error\n");
	  return (-1);
	}
      print_list(&instruc);
      /* parser(av[i], &header, &instruc); */
      free_list(&instruc);
    }
  return (0);
}
