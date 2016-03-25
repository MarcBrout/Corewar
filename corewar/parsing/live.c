/*
** live-suv.c for live-sub in /CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 21:40:56 2016 benjamin duhieu
** Last update Thu Mar 24 16:53:41 2016 marc brout
*/

#include "my.h"
#include "vm.h"

int	live(t_data *data, t_pc *i)
{
  int	chk;
  int	a;

  chk = read_int_from_ram(data->ram, MM(i->reg[0] + 1));
  /* my_printf("LIVE : %d\n", chk); */
  a = -1;
  /* my_printf("reg : %d\n", i->reg[0]); */
  while (++a < 4)
    {
      /* my_printf("data->champ[%d]->pc->reg[1] = %d\n", a, data->champ[a]->pc->reg[1]); */
      if (chk == data->champ[a]->pc->reg[1])
	{
	  my_printf("Le joueur %d %s est en vie.\n",
		    data->champ[a]->order, data->champ[a]->name);
	  data->champ[a]->alive = 1;
	  data->last = data->champ[a]->order;
	}
    }
  i->cycle = 10;
  data->nblive++;
  i->reg[0] = MM(i->reg[0] + 5);
  return (0);
}
