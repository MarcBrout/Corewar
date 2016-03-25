/*
** run_one_cycle.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Mar 22 17:00:44 2016 marc brout
** Last update Fri Mar 25 12:00:22 2016 benjamin duhieu
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
  t_pc	*tmp;
  t_pc	*elem;

  if (!(elem = malloc(sizeof(t_pc))))
    return (1);
  tmp = pc;
  while (tmp->next)
    tmp = tmp->next;
  copy_registres(tmp, elem);
  elem->champ = tmp->champ;
  elem->reg[0] = pos;
  elem->carry = tmp->carry;
  elem->cycle = cycle;
  elem->next = NULL;
  tmp->next = elem;
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

int		test_instruction(t_data *data, t_pc *pc)
{
  int		i;
  char		instruction;

  i = 0;
  /* my_printf("pc->reg[0] = %d\n", pc->reg[0]); */
  instruction = data->ram[pc->reg[0]];
  if (instruction <= 0 || instruction > VM_AFF)
    {
      pc->reg[0] += 1;
      return (0);
    }
  while (i <= VM_AFF)
    {
      if (i == instruction)
	{
	  if (data->inst[i](data, pc))
	    return (1);
	  return (0);
	}
      i += 1;
    }
  return (0);
}

int		launch_one_champ_pc(t_data *data, t_champion *champ,
				    int pc, char *go)
{
  t_pc		*tmp;

  tmp = champ->pc;
  while (--pc >= 0 && tmp->next)
    tmp = tmp->next;

  if (tmp)
    {
      if (tmp->cycle)
	tmp->cycle--;
      else
	if (test_instruction(data, tmp))
	  return (1);
      /* my_printf("tmp->next %p\n", tmp->next); */
      if (tmp->next)
	*go = 1;
      else
	*go = 0;
    }
  return (0);
}

int		run_one_cycle(t_data *data)
{
  static int	i = 1;
  char		go = 0;
  int		test;
  /* my_printf("============= turn %d live : %d ============\n", i, */
  /* 	    data->champ[0]->valid); */
  test = -1;
  while (++test < i)
    {
      if (data->champ[0]->valid >= 0)
	if (launch_one_champ_pc(data, data->champ[0], test, &go))
	  return (1);
      if (data->champ[1]->valid >= 0)
	if (launch_one_champ_pc(data, data->champ[1], test, &go))
	  return (1);
      if (data->champ[2]->valid >= 0)
	if (launch_one_champ_pc(data, data->champ[2], test, &go))
	  return (1);
      if (data->champ[3]->valid >= 0)
	if (launch_one_champ_pc(data, data->champ[3], test, &go))
	  return (1);
    }
  i += 1;
  /* my_printf("go = %d\n", go); */
  if (!go)
    i = 1;
  return (0);
}
