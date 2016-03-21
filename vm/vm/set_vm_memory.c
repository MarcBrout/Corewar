/*
** set_vm_memory.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 16:16:26 2016 marc brout
** Last update Mon Mar 21 19:48:37 2016 marc brout
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

int		check_overlap(t_champion champ[4])
{
  int		i;

  i = 0;
  while (i < 3)
    {
      if (champ[i].pc->pc > -1)
	if ((champ[i + 1].pc->pc > -1 &&
	     (champ[i].pc->pc + champ[i].size) >=
	     (champ[i + 1].pc->pc)) ||
	    (champ[i].pc->pc + champ[i].size) >= MEM_SIZE)
	  return (my_put_error(OVERLAP, 1));
      i += 1;
    }
  if ((champ[i].pc->pc > -1) &&
      (champ[i].pc->pc + champ[i].size) >= MEM_SIZE)
    return (my_put_error(OVERLAP, 1));
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
