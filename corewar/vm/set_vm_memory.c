/*
** set_vm_memory.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 16:16:26 2016 marc brout
** Last update Tue Mar 22 17:33:34 2016 marc brout
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "vm.h"
#include "my.h"

int	init_ram(t_data *data)
{
  if (!(data->ram = malloc(MEM_SIZE + 1)) ||
      !(data->ramv = malloc(MEM_SIZE + 1)))
    return (my_put_error(MALLOC_ERROR, 1));
  my_bzero(data->ram, MEM_SIZE, 0);
  my_bzero(data->ramv, MEM_SIZE - 1, 1);
  data->ramv[MEM_SIZE] = 0;
  return (0);
}

int		copy_champion_to_ram(t_champion *champion,
				     char *ram)
{
  t_header	head;
  int		fd;

  if (champion->valid)
    {
      if ((fd = open(champion->path, O_RDONLY)) < 0)
	return (my_put_file_noaccess(champion->path, -1));
      if (read(fd, &head, sizeof(t_header)) < (int)sizeof(t_header)
	  || read(fd, ram, champion->size) < champion->size)
	{
	  close(fd);
	  return (my_put_file_str(champion->path, CORRUPT, -1));
	}
      close(fd);
      /* my_printf("LOL2\n"); */
      /* my_printf("champsize = %d\n", champion->size); */
      return (champion->size);
    }
  /* my_printf("LOL3\n"); */
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
  int		rest;
  int		rest_unit;
  int		nb;
  int		pos;
  int		first;

  if ((MEM_SIZE - size_champs(data->champ, 0, &nb)) <= 0)
    return (my_put_error(OVERLAP, 1));
  first = 1;
  if ((rest = copy_champion_to_ram(data->champ[0], data->ram))
      < 0)
    return (1);
  rest = MEM_SIZE - rest;
  pos = data->champ[0]->size;
  while (first < 4 && nb > 0)
    {
      /* my_printf("MEM_SIZE = %d\n rest = %d  ", MEM_SIZE, rest); */
      /* my_printf("sizechamps = %d\n", size_champs(data->champ, first, &nb)); */
      rest_unit = (rest - size_champs(data->champ, first, &nb)) /
		   (nb + 1);
      /* my_printf("rest_unit = %d  \n", rest_unit); */
      pos += rest_unit;
      /* my_printf("first = %d, nb = %d\n", first,  nb); */
      /* my_printf("pos = %d\n", pos); */
      if (copy_champion_to_ram(data->champ[first],
			       &data->ram[pos]) < 0)
	return (1);
      pos += data->champ[first]->size;
      rest -= (rest_unit + data->champ[first]->size);
      first += 1;
    }
  return (0);
}
