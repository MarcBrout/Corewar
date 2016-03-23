/*
** run_one_cycle.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Mar 22 17:00:44 2016 marc brout
** Last update Wed Mar 23 10:20:59 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "vm.h"
#include "op.h"

void	copy_registres(t_pc *src, t_pc *dst)
{
  int	i;

  i = 0;
  while (i < 16)
    {
      dst->reg[i] = src->reg[i];
      i += 1;
    }
}

int	add_pc(t_pc *pc, int pos, int cycle)
{
  t_pc	*elem;

  if (!(elem = malloc(sizeof(t_pc))))
    return (1);
  copy_registres(pc, elem);
  elem->reg[0] = pos;
  elem->carry = pc->carry;
  elem->cycle = cycle;
  elem->next = pc->next;
  pc->next = elem;
  return (0);
}

void		init_inst(t_data *data)
{
  data->inst[VM_ERROR] = &nothing;
  data->inst[VM_LIVE] = &live;
  data->inst[VM_LD] = &ld;
  data->inst[VM_ST] = &st;
  data->inst[VM_ADD] = &add;
  data->inst[VM_SUB] = &sub;
  data->inst[VM_AND] = &and;
  data->inst[VM_XOR] = &xor;
  data->inst[VM_OR] = &or;
  data->inst[VM_LDI] = &ldi;
  data->inst[VM_LLDI] = &lldi;
  data->inst[VM_STI] = &sti;
  data->inst[VM_FORK] = &frk;
  data->inst[VM_LFORK] = &lfork;
  data->inst[VM_AFF] = &aff;
  data->inst[VM_ZJMP] = &zjump;
}

int		run_one_cycle(t_data *data)
{
  int		i;
  t_pc		*tmp;

  i = 0;
  while (i < 4)
    {
      if (data->champ[i]->alive >= 0)
	{
	  tmp = data->champ[i]->pc;
	  while (tmp)
	    {
	      // launch ptrf avec pc = tmp
	      tmp = tmp->next;
	    }
	}
      i += 1;
    }
  return (0);
}
