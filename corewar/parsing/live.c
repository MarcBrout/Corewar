/*
** live-suv.c for live-sub in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 21:40:56 2016 benjamin duhieu
** Last update Wed Mar 23 20:37:24 2016 benjamin duhieu
*/

#include "vm.h"

int	live(t_data *data, t_pc *i)
{
  int	chk;
  int	a;

  /* if (!i->said_alive) */
  /*   { */
  /*     i->champ->live_value = read_int_from_ram(data->ram, i->reg[0]); */
  /*     i->champ->said_alive = 1; */
  /*     i->champ->alive = 1; */
  /*   } */
  /* else */
  /*   { */
  chk = read_int_from_ram(data->ram, i->reg[0]);
  a = -1;
  while (data->champ[++a])
    if (chk != data->champ[a]->pc->reg[1])
      data->champ[a]->alive = 1;
  i->cycle = 10;
  data->nblive++;
  i->reg[0] += 4;
  return (0);
}
