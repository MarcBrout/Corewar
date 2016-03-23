/*
** lfork.c for lfork in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 23:01:38 2016 benjamin duhieu
** Last update Wed Mar 23 14:45:22 2016 marc brout
*/

#include "vm.h"

int	lfork(t_data *data, t_pc *i)
{
  int	val;

  val = (read_short_from_ram(data->ram, MM(i->reg[0] + 1)));
  if (add_pc(i, MM(i->reg[0] + val), 0))
    return (1);
  if (i->next->reg[0] < 0)
    i->next->reg[0] = MEM_SIZE - i->next->reg[0];
  if (val == 0)
    i->carry = 1;
  else
    i->carry = 0;
  i->cycle = 1000;
  i->reg[0] += 3;
  return (0);
}
