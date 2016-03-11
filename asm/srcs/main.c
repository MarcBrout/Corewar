/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 13:57:07 2016
** Last update Fri Mar 11 14:00:21 2016 
*/

#include "asm.h"

int		main(int ac, char **av)
{
  t_header	header;
  t_instruc	instruc;

  if (ac != 2)
    {
      write(2, "Wrong arguments\n", 16);
      return (-1);
    }
  lexer(&header, &instruc, av[1]);
  parser(&header);
}
