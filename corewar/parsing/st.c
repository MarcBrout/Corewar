/*
** st.c for st in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:50:54 2016 benjamin duhieu
** Last update Fri Mar 25 21:19:56 2016 benjamin duhieu
*/

#include "vm.h"

int	check_integrety_st(unsigned second, char *ram, int i)
{
  if ((second != 1 && (ram[MM(i + 2)] < 1 || ram[MM(i + 2)] > 16)) ||
      (second == 1 && ((ram[MM(i + 2)] < 1 || ram[MM(i + 2)] > 16) ||
		       (ram[MM(i + 3)] < 1 || ram[MM(i + 3)] > 16))))
    return (1);
  return (0);
}

void	move_pc_st(unsigned second, t_pc *i)
{
  if (second == 3)
    i->reg[0] = MM(i->reg[0] + 4);
  else
    i->reg[0] = MM(i->reg[0] + 3);
}

void		execute_st_reg(t_data *data, t_pc *i)
{
  i->reg[(int)data->ram[MM(i->reg[0] + 3)]] =
    i->reg[(int)data->ram[MM(i->reg[0] + 2)]];
  /* my_printf("st reg: st->reg[%d] = %d\n", (int)data->ram[MM(i->reg[0] + 3)], */
  /* 	    i->reg[(int)data->ram[MM(i->reg[0] + 2)]]); */
}

void		execute_st_indirect(t_data *data, t_pc *i)
{
  int		value;

  value = IDX(RSFM(data->ram, MM(i->reg[0] + 3)));
  /* my_printf("Value =%d\n", value); */
  write_int_to_ram(data->ram, i->reg[(int)data->ram[MM(i->reg[0] + 2)]],
		   MM(i->reg[0] + value));
  /* my_printf("st indir st->reg[%d] = %d\n", (int)data->ram[MM(i->reg[0] + 2)], */
  /* 	        i->reg[(int)data->ram[MM(i->reg[0] + 2)]]); */
}

int		st(t_data *data, t_pc *i)
{
  unsigned	first;
  unsigned	second;

  first = (data->ram[MM(i->reg[0] + 1)] >> 6) & (char)3;
  second = (data->ram[MM(i->reg[0] + 1)] >> 4) & (char)3;
  if (first != 1 && second != 1 && second != 3)
    return (0);
  else if (check_integrety_st(second, data->ram, i->reg[0]))
    return (0);
  if (second == 3)
    execute_st_indirect(data, i);
  else
    execute_st_reg(data, i);
  i->cycle = 5;
  move_pc_st(second, i);
  return (0);
}
