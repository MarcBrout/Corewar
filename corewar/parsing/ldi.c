/*
** ldi.c for ldi in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:57:05 2016 benjamin duhieu
** Last update Wed Mar 23 11:03:37 2016 benjamin duhieu
*/

#include "vm.h"

int	ldi(t_data *data, t_pc *i)
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
      (second != 1 && second != 2) || third != 1)
    return (0);
  else if (check_integrety_ldi(first, second, data->ram, i->reg[0]))
    return (0);
  else
    move_pc_ldi(first, second, i);
  return (0);
}
