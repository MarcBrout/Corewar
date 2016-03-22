/*
** check_stock.c for stock in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Mon Mar 14 10:10:06 2016
** Last update Mon Mar 21 19:41:41 2016 Marel la plus belle <3
*/

#include "asm.h"

int	stock_args(t_list_instruc *elem, char *arg, int pos)
{
  if (pos == 1)
    elem->info->arg_1 = my_strdup(arg);
  else if (pos == 2)
    elem->info->arg_2 = my_strdup(arg);
  else
    elem->info->arg_3 = my_strdup(arg);
  free(arg);
  return (0);
}
