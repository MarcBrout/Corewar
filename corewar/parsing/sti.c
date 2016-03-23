/*
** sti.c for sti in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:57:35 2016 benjamin duhieu
** Last update Wed Mar 23 10:37:11 2016 benjamin duhieu
*/

#include "vm.h"

int	check_integrety_sti(unsigned second, unsigned third, char *ram, int i)
{
  if (((second == 1 && third == 1) && ((ram[i + 1] < 1 || ram[i + 1] > 16) ||
				       (ram[i + 2] < 1 || ram[i + 2] > 16) ||
				       (ram[i + 3] < 1 || ram[i + 3] > 16))) ||
      ((second == 1 && third == 2) && ((ram[i + 1] < 1 || ram[i + 1] > 16) ||
				       (ram[i + 2] < 1 || ram[i + 2] > 16))) ||
      (((second == 2 || second == 3) && third == 1) && ((ram[i + 1] < 1 ||
							 ram[i + 1] > 16) ||
							(ram[i + 1] < 1 ||
							 ram[i + 4] > 16))) ||
      ((second != 1 && third != 1) && ((ram[i + 1] < 1 || ram[i + 1] > 16))))
    return (1);
  return (0);
}

void	move_pc_sti(unsigned second, unsigned third, t_pc *i)
{
  if (((second == 2 || second == 3) && third == 1) ||
      (second == 1 && third == 2))
    i->reg[0] += 5;
  else if (((second == 2 || second == 3) && third == 2))
    i->reg[0] += 6;
  else
    i->reg[0] += 4;
}

int		sti(t_data *data, t_pc *i)
{
  unsigned	first;
  unsigned	second;
  unsigned	third;

  if (g_endian)
    swap_integer(data->ram[i->reg[0]]);
  first = (data->ram[i->reg[0]] << 6) & (char)3;
  second = (data->ram[i->reg[0]] << 4) & (char)3;
  third = (data->ram[i->reg[0]] << 2) & (char)3;
  if (first != 1 || (second != 1 && second != 2 && second != 3) ||
      (third != 1 && third != 2))
    return (0);
  else if (check_integrety_sti(second, third, data->ram, i->reg[0]))
    return (0);
  else
    move_pc_sti(second, third, i);
  return (0);
}
