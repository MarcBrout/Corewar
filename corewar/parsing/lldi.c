/*
** lldi.c for lldi in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:59:12 2016 benjamin duhieu
** Last update Wed Mar 23 21:04:51 2016 benjamin duhieu
*/

#include "vm.h"

int	check_integrety_ldi(unsigned first, unsigned second, char *ram, int i)
{
  if (((first == 1 && second == 2) &&
       ((ram[i + 1] < 1 || ram[i + 1] > 16) ||
	(ram[i + 4] < 1 || ram[i + 4] > 16))) ||
      (((first == 2 || first == 3) && second == 1) &&
       ((ram[i + 3] < 1 || ram[i + 3] > 16) ||
	(ram[i + 4] < 1 || ram[i + 4] > 16))) ||
      (((first == 2 || first == 3) && second == 2) &&
       (ram[i + 5] < 1 || ram[i + 5] > 16)) ||
      ((first == 1 && second == 1) &&
       ((ram[i + 1] < 1 || ram[i + 1] > 16) ||
	(ram[i + 2] < 1 || ram[i + 2] > 16) ||
	(ram[i + 2] < 1 || ram[i + 3] > 16))))
    return (1);
  return (0);
}


int		perform_lldi(t_data *data, t_val *val, t_pc *i)
{
  if (val->type[0])
    {
      if (val->type[1])
	i->reg[val->inte[2]] =
	  (int)data->ram[MM(i->reg[0] + val->inte[0])] + val->inte[1];
      else
	i->reg[val->inte[2]] =
	  (int)data->ram[MM(i->reg[0] + val->inte[0])] + val->shrt[1];
    }
  else
    {
      if (val->type[1])
	i->reg[val->inte[2]] =
	  (int)data->ram[MM(i->reg[0] + val->shrt[0])] +
	  val->inte[1];
      else
	i->reg[val->inte[2]] =
	  (int)data->ram[MM(i->reg[0] + IDX(val->shrt[0]))] +
	  val->shrt[1];
    }
  return (i->reg[val->inte[2]]);
}

int		lldi(t_data *data, t_pc *i)
{
  t_inst	inst;
  t_val		val;
  int		move;

  inst.fi = (data->ram[i->reg[0]] >> 6) & (char)3;
  inst.sd = (data->ram[i->reg[0]] >> 4) & (char)3;
  inst.th = (data->ram[i->reg[0]] >> 2) & (char)3;
  if ((inst.fi != 1 && inst.fi != 2 && inst.fi != 3) ||
      (inst.sd != 1 && inst.sd != 2) || inst.th != 1)
    return (0);
  if (check_integrety_ldi(inst.fi, inst.sd, data->ram, i->reg[0]))
    return (0);
  move = recup_val(data, i, &inst, &val);
  if (perform_lldi(data, &val, i))
    i->carry = 0;
  else
    i->carry = 1;
  i->reg[0] = MM(i->reg[0] + move);
  i->cycle = 50;
  return (0);
}
