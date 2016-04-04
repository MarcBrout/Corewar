/*
** nothing.c for nothing in /home/duhieu_b/CPE/CPE_2015_corewar/corewar
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Wed Mar 23 10:43:34 2016 benjamin duhieu
** Last update Sun Mar 27 12:47:53 2016 marc brout
*/

#include "vm.h"

void	free_pc(t_pc *i)
{
  i->prev->next = i->next;
  if (i->next)
    i->next->prev = i->prev;
  free(i);
}

int	nothing(UNUSED t_data *data, t_pc *i)
{
  free_pc(i);
  return (0);
}
