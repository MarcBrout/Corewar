/*
** set_vm_memory.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 16:16:26 2016 marc brout
** Last update Mon Mar 21 22:57:20 2016 marc brout
*/

#include "vm.h"

int	init_ram(t_data *data)
{
  if (!(data->ram = malloc(sizeof(MEM_SIZE + 1))) ||
      !(data->ramv = malloc(sizeof(MEM_SIZE + 1))))
    return (my_put_error(MALLOC_ERROR, 1));
  my_bzero(data->ram, MEM_SIZE + 1, 0);
  my_bzero(data->ramv, MEM_SIZE, 1);
  data->ramv[MEM_SIZE] = 0;
  return (0);
}

int		check_champs(t_champion *champ1,
			     t_champion *champ2)
{
  int		pos;
  int		pos2;

  if (champ1->valid && champ2->valid)
    {
      if (champ1->pc->pc > -1 && champ2->pc->pc > -1)
	{
	  pos = champ1->pc->pc + champ1->size;
	  pos2 = champ2->pc->pc + champ2->size;
	  if ((pos >= champ2->pc->pc && pos <= pos2) ||
	      (pos2 >= champ1->pc->pc && pos2 <= pos) ||
	      (pos >= MEM_SIZE || pos2 >= MEM_SIZE))
	    return (1);
	}
    }
  else if (champ1->valid && champ1->pc->pc > -1
	   champ1->pc->pc + champ1->size >= MEM_SIZE)
    return (1);
  else
    if (champ2->valid && champ2->pc->pc > -1
	champ2->pc->pc + champ2->size >= MEM_SIZE)
      return (1);
  return (0);
}

int		check_overlap(t_champion *champ[4])
{
  int		i;
  int		j;

  i = -1;
  while (++i < 4)
    {
      j = -1;
      while (++j < 4)
	{
	  if (j != i)
	    {
	      if (check_champs(champ[i], champ[j]))
		return (1);
	    }
	}
    }
  return (0);
}

int		copy_champion_to_ram(t_champion *champion,
				     char *ram)
{
  t_header	head;
  int		fd;
  int		i;

  if ((fd = open(champion->path, O_RDONLY)) < 0)
    return (my_put_file_noaccess(champion->path, 1));
  if (read(fd, &head, sizeof(t_header)) < sizeof(t_header) ||
      read(fd, &ram[champion->pc->pc], champion->size) <
      champion->size)
    {
      close(fd);
      return (my_put_file_str(champion->path, CORRUPT, 1));
    }
  close(fd);
  return (0);
}

int		size_champs(t_champion *champ[4],
			    int first,
			    int *nb)
{
  int		i;
  int		total;

  i = first;
  total = 0;
  *nb = 0;
  while (i < 4)
    {
      if (champ[i]->valid)
	{
	  total += champ[i]->size;
	  *nb += 1;
	}
      i += 1;
    }
  return (total);
}

int		place_all_champions(t_data *data)
{
  int		rest_unit;
  int		nb;
  int		pos;
  int		first;

  if ((MEM_SIZE - size_champs(data->champ, &nb)) <= 0)
    return (my_put_error(OVERLAP, 1));
  first = 1;
  copy_champion_to_ram(data->champ[0], data->ram);
  rest = MEM_SIZE - data->champ[0]->size;
  pos = data->champ[0]->size;
  nb -= 1;
  while (first < 4 && nb > 0)
    {
      rest_unit = rest / (nb + 1);
      pos += rest;
      copy_champion_to_ram(data->champ[first], data->ram);
      rest -= (data->champ[first]->size + rest_unit);
      first += 1;
      nb - 1;
    }
  return (0);
}
