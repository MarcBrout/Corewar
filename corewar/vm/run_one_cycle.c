/*
** run_one_cycle.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Mar 22 17:00:44 2016 marc brout
** Last update Sat Mar 26 18:06:55 2016 benjamin duhieu
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
  elem->reg[0] = (pos < 0) ? MEM_SIZE + pos : pos % MEM_SIZE;
  elem->carry = tmp->carry;
  elem->cycle = cycle;
  elem->cycle = 0;
  elem->run = 0;
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
  data->inst[VM_LLD] = &lld;
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
      if (test_instruction(data, tmp))
	return (1);
      if (tmp->next)
	*go = 1;
      else
	*go = 0;
    }
  return (0);
}

int		run_one_cycle(t_data *data)
{
  char		go;
  int		test;

  test = -1;
  go = 1;
  while (go)
    {
      test++;
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
  return (0);
}
