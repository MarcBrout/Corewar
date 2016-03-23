/*
** aff.c for aff in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 23:01:53 2016 benjamin duhieu
** Last update Tue Mar 22 19:12:08 2016 benjamin duhieu
*/

#include "vm.h"

int		aff(t_data *data, t_pc *i)
{
  unsigned	first;

  if (g_endian)
    swap_integer(data->ram[i->reg[0]]);
  first = (data->ram[i->reg[0]] << 6) & (char)3;
  if (first != 1)
    return (1);
  else if (data->ram[i->reg[0] + 1] < 1 || data->ram[i->reg[0] + 1] > 16)
    return (1);
  else
    i->reg[0] += 2;
  return (0);
}
