/*
** fork.c for fork in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:58:14 2016 benjamin duhieu
** Last update Wed Mar 23 15:08:09 2016 marc brout
*/

#include "vm.h"

int	frk(t_data *data, t_pc *i)
{
  int	val;

  val = (read_short_from_ram(data->ram, MM(i->reg[0] + 1)) % IDX_MOD);
  if (add_pc(i, MM(i->reg[0] + val), 0))
    return (1);
  if (i->next->reg[0] < 0)
    i->next->reg[0] = MEM_SIZE - i->next->reg[0];
  i->cycle = 800;
  i->reg[0] += 3;
  return (0);
}
