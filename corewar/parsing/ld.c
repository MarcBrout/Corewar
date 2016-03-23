/*
** ld.c for ld in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:50:12 2016 benjamin duhieu
** Last update Wed Mar 23 10:29:52 2016 benjamin duhieu
*/

#include "vm.h"

int		ld(t_data *data, t_pc *i)
{
  unsigned	first;
  unsigned	second;

  if (g_endian)
    swap_integer(data->ram[i->reg[0]]);
  first = (data->ram[i->reg[0]] << 6) & (char)3;
  second = (data->ram[i->reg[0]] << 4) & (char)3;
  if ((first != 2 && first != 3) || second != 1)
    return (0);
  else if (check_integrety_ld(first, data->ram, i->reg[0]))
    return (0);
  else
    move_pc_ld(first, i);
  return (0);
}
