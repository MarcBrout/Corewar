/*
** ld.c for ld in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:50:12 2016 benjamin duhieu
** Last update Fri Mar 25 10:59:51 2016 benjamin duhieu
*/

#include "vm.h"
#include "my.h"

void		execute_ld_direct(t_data *data, t_pc *i)
{
  int		dir;

  dir = IDX(RIFM(data->ram, MM(i->reg[0] + 2)));
  if (dir == 0)
    i->carry = 1;
  else
    i->carry = 0;
  /* my_printf("check exec ld dir%d\n", (int)data->ram[MM(i->reg[0] + 6)]); */
  i->reg[(int)data->ram[MM(i->reg[0] + 6)]] = dir;
}

void		execute_ld_indirect(t_data *data, t_pc *i)
{
  int		indir;
  int		value;

  value = IDX(RSFM(data->ram, MM(i->reg[0] + 2)));
  indir = IDX(RIFM(data->ram, MM(i->reg[0] + value)));
  if (indir == 0)
    i->carry = 1;
  else
    i->carry = 0;
  /* my_printf("check exec ld ind%d\n", (int)data->ram[MM(i->reg[0] + 4)]); */
  i->reg[(int)data->ram[MM(i->reg[0] + 4)]] = indir;
}

int		ld(t_data *data, t_pc *i)
{
  unsigned	first;
  unsigned	second;

  /* my_printf("LD\n"); */
  /* my_printf("code byte = %d\n", (int)data->ram[MM(i->reg[0] + 1)]); */
  first = (data->ram[MM(i->reg[0] + 1)] >> 6) & (char)3;
  second = (data->ram[MM(i->reg[0] + 1)] >> 4) & (char)3;
  /* my_printf("first byte = %d\n", first); */
  /* my_printf("second byte = %d\n", second); */
  if ((first != 2 && first != 3) || second != 1)
    return (0);
  if (check_integrety_ld(first, data->ram, i->reg[0]))
    return (0);
  if (first == 2)
    execute_ld_direct(data, i);
  else
    execute_ld_indirect(data, i);
  i->cycle = 5;
  move_pc_ld(first, i);
  /* my_printf("LD - i->reg[0] - AFTER MOVE RECHECK = %d \n", i->reg[0]); */
  return (0);
}
