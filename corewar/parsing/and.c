/*
** and.c for and in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:54:20 2016 benjamin duhieu
** Last update Wed Mar 23 16:15:41 2016 marc brout
*/

#include "vm.h"

int	check_integrety(unsigned f, unsigned s, char *r, int i)
{
  if (((f == 3 && s == 3) && (r[M(i + 5)] < 1 || r[M(i + 5)] > 16)) ||
      ((f == 2 && s == 2) && (r[M(i + 9)] < 1 || r[M(i + 9)] > 16)) ||
      (((f == 3 && s == 2) || (f == 2 && s == 3)) &&
       (r[M(i + 7)] < 1 || r[M(i + 7)] > 16)) ||
      ((f == 1 && s == 2) && ((r[M(i + 1)] < 1 || r[M(i + 1)] > 16) ||
			      (r[M(i + 6)] < 1 || r[M(i + 6)] > 16))) ||
      ((f == 1 && s == 3) && ((r[M(i + 1)] < 1 || r[M(i + 1)] > 16) ||
			      (r[M(i + 4)] < 1 || r[M(i + 4)] > 16))) ||
      ((f == 2 && s == 1) && ((r[M(i + 5)] < 1 || r[M(i + 5)] > 16) ||
			      (r[M(i + 6)] < 1 || r[M(i + 6)] > 16))) ||
      ((f == 3 && s == 1) && ((r[M(i + 3)] < 1 || r[M(i + 3)] > 16) ||
			      (r[M(i + 4)] < 1 || r[M(i + 4)] > 16))) ||
      ((f == 1 && s == 1) && ((r[M(i + 1)] < 1 || r[M(i + 1)] > 16) ||
			      (r[M(i + 2)] < 1 || r[M(i + 2)] > 16) ||
			      (r[M(i + 3)] < 1 || r[M(i + 3)] > 16))))
    return (1);
  return (0);
}

int		recup_val(t_data *data,
			  t_pc *i,
			  t_inst *inst,
			  t_val *val)
{
  int		pos;

  pos = 2;
  if (inst->fi == 1)
    val->inte[1] = i->reg[(int)data->ram[M(i->reg[0] + pos)]], pos += 1;
  if (inst->fi == 2)
    val->shrt[1] = RSFM(data->ram, M(i->reg[0] + pos)), pos += 2;
  if (inst->fi == 3)
    val->inte[1] = RIFM(data->ram, M(i->reg[0] + pos)), pos += 4;
  if (inst->sd == 1)
    val->inte[2] = i->reg[(int)data->ram[M(i->reg[0] + pos)]], pos += 1;
  if (inst->sd == 2)
    val->shrt[2] = RSFM(data->ram, M(i->reg[0] + pos)), pos += 2;
  if (inst->sd == 3)
    val->inte[2] = RIFM(data->ram, M(i->reg[0] + pos)), pos += 4;
  val->inte[3] = i->reg[(int)data->ram[MM(i->reg[0] + pos)]], pos += 1;
  return (pos);
}

/* int		perform_and(t_data *data, */
/* 			    t_pc *i, */
/* 			    t_inst *inst, */
/* 			    t_val *val) */
/* { */
/* } */

int		and(t_data *data, t_pc *i)
{
  t_inst	inst;
  t_val		val;
  int		move;

  inst.fi = (data->ram[i->reg[0]] << 6) & (char)3;
  inst.sd = (data->ram[i->reg[0]] << 4) & (char)3;
  inst.th = (data->ram[i->reg[0]] << 2) & (char)3;
  if ((inst.fi != 1 && inst.fi != 2 && inst.fi != 3) ||
      (inst.sd != 1 && inst.sd != 2 && inst.sd != 3) || inst.th != 1)
    return (0);
  if (check_integrety(inst.fi, inst.sd, data->ram, i->reg[0] + 1))
    return (0);
  move = recup_val(data, i, &inst, &val);
  i->reg[0] = MM(i->reg[0] + move);
  i->cycle = 6;
  return (0);
}
