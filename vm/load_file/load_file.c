/*
** load_file.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 12:07:50 2016 marc brout
** Last update Mon Mar 21 14:08:34 2016 marc brout
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fnctl.h>
#include "load.h"
#include "op.h"

char		endian;

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

  if ((ret = read(fd, head, sizeof(t_header))
       < (int)sizeof(t_header)))
    return (1);
  if (endian)
    {
      head->magic = swap_integer(head->magic);
      head->prog_size = swap_integer(head->prog_size);
    }
  if (head.magic != COREWAR_EXEC_MAGIC)
    return (1);
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

t_champion	*load_champion(const char *champion_file, int order)
{
  t_champion	*champion;
  t_header	head;
  int		fd;

  if (!(champion = malloc(sizeof(t_champion))) ||
      !(champion->pc = malloc(sizeof(t_pc))) ||
      (fd = open(champion_file, O_RDONLY)) < 0 ||
      check_header(fd, &head))
    return (NULL);
  my_bzero(champion->name, PROG_NAME_LENGTH + 1);
  my_strcpy(head->prog_name, champion->name);
  champion->valid = 1;
  champion->alive = 1;
  champion->order = order;
  champion->next = NULL;
  return (champion);
}

int	main(int ac, char **av)
{
  endian = endianness();
  load_champion(av[1]);
  return (0);
}
