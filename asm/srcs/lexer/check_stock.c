/*
** check_stock.c for stock in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Mon Mar 14 10:10:06 2016
** Last update Mon Mar 14 10:52:24 2016 
*/

#include "asm.h"

int	stock_args(t_list_instruc *elem, char *arg, int pos)
{
  if (pos == 1)
    {
      if ((elem->info->arg_1 =
	   malloc(sizeof(char) * (my_strlen(arg) + 1))) == NULL)
	return (malloc_fail(), -1);
      elem->info->arg_1 = arg;
    }
  else if (pos == 2)
    {
      if ((elem->info->arg_2 =
	   malloc(sizeof(char) * (my_strlen(arg) + 1))) == NULL)
	return (malloc_fail() , -1);
      elem->info->arg_2 = arg;
    }
  else
    {
      if ((elem->info->arg_3 =
	   malloc(sizeof(char) * (my_strlen(arg) + 1))) == NULL)
	return (malloc_fail(), -1);
      elem->info->arg_3 = arg;
    }
  return (0);
}
