/*
** and.c for and in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:54:20 2016 benjamin duhieu
** Last update Wed Mar 23 10:29:14 2016 benjamin duhieu
*/

#include "vm.h"

int	check_integrety(unsigned first, unsigned second, char *ram, int i)
{
  if (((first == 3 && second == 3) && (ram[i + 5] < 1 || ram[i + 5] > 16)) ||
      ((first == 2 && second == 2) && (ram[i + 9] < 1 || ram[i + 9] > 16)) ||
      (((first == 3 && second == 2) || (first == 2 && second == 3)) &&
       (ram[i + 7] < 1 || ram[i + 7] > 16)) ||
      ((first == 1 && second == 2) && ((ram[i + 1] < 1 || ram[i + 1] > 16) ||
				       (ram[i + 6] < 1 || ram[i + 6] > 16))) ||
      ((first == 1 && second == 3) && ((ram[i + 1] < 1 || ram[i + 1] > 16) ||
				       (ram[i + 4] < 1 || ram[i + 4] > 16))) ||
      ((first == 2 && second == 1) && ((ram[i + 5] < 1 || ram[i + 5] > 16) ||
				       (ram[i + 6] < 1 || ram[i + 6] > 16))) ||
      ((first == 3 && second == 1) && ((ram[i + 3] < 1 || ram[i + 3] > 16) ||
				       (ram[i + 4] < 1 || ram[i + 4] > 16))) ||
      ((first == 1 && second == 1) && ((ram[i + 1] < 1 || ram[i + 1] > 16) ||
				       (ram[i + 2] < 1 || ram[i + 2] > 16) ||
				       (ram[i + 3] < 1 || ram[i + 3] > 16))))
    return (1);
  return (0);
}

void	move_pc(unsigned first, unsigned second, t_pc *i)
{
  if (first == 2 && second == 2)
    i->reg[0] += 10;
  else if ((first == 2 && second == 3) || (first == 3 && second == 2))
    i->reg[0] += 8;
  else if ((first == 1 && second == 2) || (first == 2 && second == 1))
    i->reg[0] += 7;
  else if ((first == 1 && second == 3) || (first == 3 && second == 1))
    i->reg[0] += 5;
  else if (first == 3 && second == 3)
    i->reg[0] += 6;
  else
    i->reg[0] += 4;
}

int		and(t_data *data, t_pc *i)
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
    return (0);
  else if (check_integrety(first, second, data->ram, i->reg[0]))
    return (0);
  else
    move_pc(first, second, i);
  return (0);
}
