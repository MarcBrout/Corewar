/*
** error_stop.c for error_stop in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/error
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 14:10:16 2016
** Last update Tue Mar 22 11:24:32 2016 marel_m
*/

#include "asm.h"
#include <unistd.h>

void	malloc_fail()
{
  write(2, "Can't perform malloc\n", 21);
}

void	file_wrong(char *str)
{
  my_printf("File %s not accessible\n", str);
}

void	no_exist_label(t_instruc *instruc, char *str)
{
  my_printf("Label %s undefine line %d\n", str, instruc->nb_l);
}

void	synthax_error(t_instruc *instruc)
{
  my_printf("Synthax error line %d\n", instruc->nb_l);
}
