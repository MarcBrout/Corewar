/*
** ldi.c for ldi in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:57:05 2016 benjamin duhieu
** Last update Wed Mar 23 17:55:01 2016 marc brout
*/

#include "vm.h"

int		perform_ldi(t_data *data, t_val *val, t_pc *i)
{
  if (val->type[0])
    {
      if (val->type[1])
	i->reg[val->inte[2]] =
	  (int)data->ram[MM(i->reg[0] + IDX(val->inte[0]))] +
	  IDX(val->inte[1]);
      else
	i->reg[val->inte[2]] =
	  (int)data->ram[MM(i->reg[0] + IDX(val->inte[0]))] +
	  IDX(val->shrt[1]);
    }
  else
    {
      if (val->type[1])
	i->reg[val->inte[2]] =
	  (int)data->ram[MM(i->reg[0] + IDX(val->shrt[0]))] +
	  IDX(val->inte[1]);
      else
	i->reg[val->inte[2]] =
	  (int)data->ram[MM(i->reg[0] + IDX(val->shrt[0]))] +
	  IDX(val->shrt[1]);
    }
  return (i->reg[val->inte[2]]);
}

int		ldi(t_data *data, t_pc *i)
{
  t_inst	inst;
  t_val		val;
  int		move;

  inst.fi = (data->ram[i->reg[0]] << 6) & (char)3;
  inst.sd = (data->ram[i->reg[0]] << 4) & (char)3;
  inst.th = (data->ram[i->reg[0]] << 2) & (char)3;
  if ((inst.fi != 1 && inst.fi != 2 && inst.fi != 3) ||
      (inst.sd != 1 && inst.sd != 2) || inst.th != 1)
    return (0);
  if (check_integrety_ldi(inst.fi, inst.sd, data->ram, i->reg[0]))
    return (0);
  move = recup_val(data, i, &inst, &val);
  if (perform_ldi(data, &val, i))
    i->carry = 0;
  else
    i->carry = 1;
  i->reg[0] = MM(i->reg[0] + move);
  i->cycle = 25;
  return (0);
}
