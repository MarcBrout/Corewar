/*
** live-suv.c for live-sub in /CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 21:40:56 2016 benjamin duhieu
** Last update Thu Mar 24 12:32:59 2016 benjamin duhieu
*/

#include "my.h"
#include "vm.h"

int	live(t_data *data, t_pc *i)
{
  int	chk;
  int	a;

  chk = read_int_from_ram(data->ram, MM(i->reg[0] + 1));
  my_printf("LIVE\n");
  a = -1;
  printf("reg : %d\n", i->reg[0]);
  while (++a < 4)
    {
      printf("chk = %d, data->champ[a] : %d\n", chk, data->champ[a]->pc->reg[1]);
      if (chk == data->champ[a]->pc->reg[1] && data->champ[a]->alive == 0)
	data->champ[a]->alive = 1;
    }
  i->cycle = 10;
  data->nblive++;
  i->reg[0] = MM(i->reg[0] + 5);
  return (0);
}
