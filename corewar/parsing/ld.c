/*
** ld.c for ld in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:50:12 2016 benjamin duhieu
** Last update Wed Mar 23 13:41:32 2016 benjamin duhieu
*/

#include "vm.h"

void		execute_ld_direct(t_data *data, t_pc *i)
{
  int		dir;

  dir = data->ram[MM(i->reg[0] + 2)];
  if (dir == 0)
    i->carry = 1;
  i->reg[data->ram[MM(i->reg[0] + 3)]] = dir;
}

void		execute_ld_indirect(t_data *data, t_pc *i)
{
  int		dir;

  dir = data->ram[MM(i->reg[0] + data->ram[MM(i->reg[0] + 2)])];
  if (dir == 0)
    i->carry = 1;
  i->reg[data->ram[MM(i->reg[0] + 3)]] = dir;
}

int		ld(t_data *data, t_pc *i)
{
  unsigned	first;
  unsigned	second;

  first = ((data->ram[MM(i->reg[0]] + 1)) << 6) & (char)3;
  second = ((data->ram[MM(i->reg[0]] + 1)) << 4) & (char)3;
  if ((first != 2 && first != 3) || second != 1)
    return (0);
  if (check_integrety_ld(first, data->ram, i->reg[0]))
    return (0);
  if (second == 2)
    execute_ld_direct(data, i);
  else
    execute_ld_indirect(data, i);
  move_pc_ld(first, i);
  return (0);
}
