/*
** sub.c for sub in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:53:41 2016 benjamin duhieu
** Last update Wed Mar 23 10:31:46 2016 benjamin duhieu
*/

#include "vm.h"

int		sub(t_data *data, t_pc *i)
{
  unsigned	first;
  unsigned	second;
  unsigned	third;

  if (g_endian)
    swap_integer(data->ram[i->reg[0]]);
  first = (data->ram[i->reg[0]] << 6) & (char)3;
  second = (data->ram[i->reg[0]] << 4) & (char)3;
  third = (data->ram[i->reg[0]] << 2) & (char)3;
  if (first != 1 || second != 1 || third != 1)
    return (0);
  else if ((data->ram[i->reg[0] + 1] < 1 || data->ram[i->reg[0] + 1] > 16) ||
	   (data->ram[i->reg[0] + 2] < 1 || data->ram[i->reg[0] + 2] > 16) ||
	   (data->ram[i->reg[0] + 3] < 1 || data->ram[i->reg[0] + 3] > 16))
    return (0);
  i->reg[0] += 4;
  return (0);
}
