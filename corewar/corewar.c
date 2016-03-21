/*
** corewar.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Mar 15 19:00:28 2016 marc brout
** Last update Tue Mar 15 19:39:20 2016 marc brout
*/

#include "corewar.h"

void		fill_list_number(t_champion *root)
{
  t_champion	*champion;
  int		i;

  champion = root->next;
  i = 1;
  while (champion)
    {
      if (champion->nb == -1)
	{
	  while (!is_nb_present(i, root))
	    i += 1;
	  champion->nb = i;
	  i += 1;
	}
      champion = champion->next;
    }
}

int		is_nb_present(int nb, t_champion *root)
{
  t_champion	*champion;

  champion = root->next;
  while (champion)
    {
      if (champion->nb == nb)
	return (1);
      champion = champion->next;
    }
  return (0);
}

int		add_champ_to_list(t_header *header,
				  t_champion *root,
				  int nb)
{
  t_champion	*elem;
  t_champion	*tmp;
  int		i;

  if (!(elem = malloc(sizeof(t_champion))) ||
      !(elem->name = my_strdup(header->prog_name)))
    return (1);
  elem->nb = nb;
  elem->next = NULL;
  tmp = root->next;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = elem;
}
