/*
** live-suv.c for live-sub in /CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 21:40:56 2016 benjamin duhieu
** Last update Thu Mar 24 12:26:43 2016 marc brout
*/

#include "my.h"
#include "vm.h"

int	live(t_data *data, t_pc *i)
{
  int	chk;
  int	a;

  my_printf("LIVE\n");
  chk = read_int_from_ram(data->ram, i->reg[0]);
  a = -1;
  while (++a < 4)
    if (chk == data->champ[a]->pc->reg[1])
      data->champ[a]->alive = 1;
  i->cycle = 10;
  data->nblive++;
  i->reg[0] = MM(i->reg[0] + 5);
  return (0);
}
