/*
** lld.c for lld in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:58:34 2016 benjamin duhieu
** Last update Tue Mar 22 18:58:40 2016 benjamin duhieu
*/

#include "vm.h"

int	check_integrety_ld(unsigned first, char *ram, int i)
{
  if ((first == 2 && (ram[i + 5] < 1 || ram[i + 5] > 16)) ||
      (first == 3 && (ram[i + 3] < 1 || ram[i + 3] > 16)))
    return (1);
  return (0);
}

void	move_pc_ld(unsigned first, t_pc *i)
{
  if (first == 2)
    i->reg[0] += 6;
  else
    i->reg[0] += 4;
}

int		lld(t_data *data, t_pc *i)
{
  unsigned	first;
  unsigned	second;

  if (g_endian)
    swap_integer(data->ram[i->reg[0]]);
  first = (data->ram[i->reg[0]] << 6) & (char)3;
  second = (data->ram[i->reg[0]] << 4) & (char)3;
  if ((first != 1 && first != 2 && first != 3) || second != 1)
    return (1);
  else if (check_integrety(first, data->ram, i->reg[0]))
    return (1);
  else
    move_pc_ld(first, i);
  return (0);
}
