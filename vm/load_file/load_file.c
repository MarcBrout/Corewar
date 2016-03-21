/*
** load_file.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 12:07:50 2016 marc brout
** Last update Mon Mar 21 23:02:53 2016 marc brout
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fnctl.h>
#include "load.h"
#include "op.h"

char		endianness()
{
  int		i;
  char		*x;

  i = 1;
  x = (char *)&i;
  return (x[0]);
}

int		swap_integer(int nb)
{
  ret = ((nb >> 24) & 0xff) | ((nb <<8) & 0xff0000) |
    ((nb >> 8) & 0xff00) | ((nb << 24) & 0xff000000);
  return (ret);
}

int		check_header(int fd, t_header *head)
{
  int		ret;
  int		size;
  char		c;

  if ((ret = read(fd, head, sizeof(t_header)) <
       (int)sizeof(t_header)))
    return (1);
  if (endian)
    {
      head->magic = swap_integer(head->magic);
      head->prog_size = swap_integer(head->prog_size);
    }
  if (head.magic != COREWAR_EXEC_MAGIC)
    return (2);
  size = 0;
  while ((ret = read(fd, &c, 1)))
    size += 1;
  if (size != head->prog_size)
    return (1);
  return (0);
}

void		copy(char *src, char *dst)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dst[i] = src[i];
      i += 1;
    }
}

int		init_champs(t_data *data)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      if (!(data->champ[i] = malloc(sizeof(t_champion))) ||
	  !(data->champ[i]->pc = malloc(sizeof(t_pc))))
	return (my_put_error(MALLOC_ERROR, 1));
      data->champ[i]->pc->pc = -1;
      data->champ[i]->valid = 0;
      data->champ[i]->alive = 1;
      data->champ[i]->order = -1;
      my_bzero(data->champ[i]->name,
	       PROG_NAME_LENGTH + 1, 0);
    }
  return (0);
}

int		load_champion(t_champion *champion,
			      const char *champion_file)
{
  t_header	head;
  int		fd;
  int		err;

  if (my_revstrncmpcst(champion_file, ".cor", 4))
    return (my_put_file_str(champion_file, NOCOREWAR, 1));
  if ((fd = open(champion_file, O_RDONLY)) < 0)
    return (my_put_file_noaccess(champion_file, 1));
  if ((err = check_header(fd, &head)))
    {
      close(fd);
      if (err == 2)
	return (my_put_file_str(champion_file, NOCOREWAR, 1));
      return (my_put_file_str(champion_file, CORRUPT, 1));
    }
  champion->path = champion_file;
  champion->size = head->prog_size;
  my_strcpy(head->prog_name, champion->name);
  close(fd);
  return (0);
}

int	main(int ac, char **av)
{
  g_endian = endianness();
  load_champion(av[1]);
  return (0);
}
