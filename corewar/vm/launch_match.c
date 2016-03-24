/*
** launch_match.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Mar 22 15:44:56 2016 marc brout
** Last update Wed Mar 23 20:45:27 2016 marc brout
*/

#include "vm.h"
#include "my.h"

int		count_players_alive(t_champion *champ[4])
{
  int		i;
  int		total;

  i = 0;
  total = 0;
  while (i < 4)
    {
      if (champ[i]->alive >= 1)
	{
	  my_printf("Le joueur %d %s est en vie\n",
		    champ[i]->order,
		    champ[i]->name);
	  total += 1;
	}
      i += 1;
    }
  return (total);
}

void		set_players(t_champion *champ[4])
{
  int		i;

  i = 0;
  while (i < 4)
    {
      if ((champ[i]->alive) >= 1)
	champ[i]->alive = 0;
      else
	champ[i]->alive = -1;
      i += 1;
    }
}

void		check_winner(t_champion *champ[4])
{
  int		i;
  char		winner;

  i = 0;
  winner = 0;
  while (++i < 4)
    if (champ[i]->alive > 0 && (winner = 1))
      my_printf("Le joueur %d %s à gagné\n", champ[i]->order,
		champ[i]->name);
  if (!winner)
    while (++i < 4)
      if (champ[i]->alive == 0)
	my_printf("Le joueur %d %s à gagné\n", champ[i]->order,
		  champ[i]->name);
}

void		copy_order_to_reg(t_champion *champ[4])
{
  int		i;

  i = 0;
  while (i < 4)
    {
      champ[i]->pc->reg[1] = champ[i]->order;
      i += 1;
    }
}

int		launch_match(t_data *data)
{
  char		go;
  int		i;
  int		nb_turn;

  i = 0;
  data->nblive = 0;
  nb_turn = CYCLE_TO_DIE;
  go = 1;
  init_inst(data);
  set_players(data->champ);
  while (go && nb_turn >= 0)
    {
      if (run_one_cycle(data))
	return (1);
      if (data->dump > 0)
	if (!(data->dump -= 1))
	  return (dump(data->ram), 0);
      if (data->nblive >= NBR_LIVE && !(data->nblive = 0))
	if ((nb_turn -= CYCLE_DELTA) <= 0)
	  break ;
      if (i >= nb_turn && !(i = 0))
	{
	  go = count_players_alive(data->champ);
	  set_players(data->champ);
	}
      i += 1;
    }
  check_winner(data->champ);
  return (0);
}
