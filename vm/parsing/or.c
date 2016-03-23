/*
** or.c for or in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:55:18 2016 benjamin duhieu
** Last update Tue Mar 22 19:03:03 2016 benjamin duhieu
*/

#include "vm.h"

int		or(t_data *data, t_pc *i)
{
  unsigned	first;
  unsigned	second;
  unsigned	third;

  if (g_endian)
    swap_integer(data->ram[i->reg[0]]);
  first = (data->ram[i->reg[0]] << 6) & (char)3;
  second = (data->ram[i->reg[0]] << 4) & (char)3;
  third = (data->ram[i->reg[0]] << 2) & (char)3;
  if ((first != 1 && first != 2 && first != 3) ||
      (second != 1 && second != 2 && second != 3) || third != 1)
    return (1);
  else if (check_integrety(first, second, data->ram, i->reg[0]))
    return (1);
  else
    move_pc(first, second, i);
  return (0);
}
