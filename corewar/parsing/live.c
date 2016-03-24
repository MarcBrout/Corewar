/*
** live-suv.c for live-sub in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 21:40:56 2016 benjamin duhieu
** Last update Thu Mar 24 11:41:53 2016 marc brout
** Last update Thu Mar 24 11:07:37 2016 benjamin duhieu
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
  i->reg[0] += 5;
  return (0);
}
