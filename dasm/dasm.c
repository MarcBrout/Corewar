/*
** dasm.c for corewar in /home/brout_m/RENDU/CPE/CPE_2015_corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 14 10:48:24 2016 marc brout
** Last update Mon Mar 14 15:42:15 2016 marc brout
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "dasm.h"
#include "op.h"

int	my_print_error(const char *str, int err)
{
  int	i;

  i = 0;
  while (str && str[i])
    {
      write(1, &str[i], 1);
      i += 1;
    }
  return (err);
}

int		test_endianness()
{
  int		i;
  char		*x;

  i = 1;
  x = (char *)&i;
  return (x[0]);
}

int		swap_integer(int nb)
{
  int		ret;

  ret = ((nb >> 24) & 0xff) |
    ((nb << 8) & 0xff0000) |
    ((nb >> 8) & 0xff00) |
    ((nb << 24) & 0xff000000);
  return (ret);
}

int		dasm(const char *file)
{
  int		fd;
  header_t	head;

  if ((fd = open(file, O_RDONLY)) < 0 ||
      (read(fd, &head, sizeof(header_t))) < (int)sizeof(header_t))
    return (1);
  my_printf("magic = %x\nProg_name = %s\nProg_size = %d\ncomment = %s\n",
	    head.magic, head.prog_name, head.prog_size / 8, head.comment);
  printf("%x, %x\n", (unsigned int)head.magic, COREWAR_EXEC_MAGIC);
  if (test_endianness())
    head.magic = swap_integer(head.magic);
  if ((head.magic != COREWAR_EXEC_MAGIC) || (!head.prog_size))
    return (1);
  return (0);
}

int	main(int ac, char **av)
{
  if (ac < 2 || !av[1][0])
    return (my_print_error(USAGE, 1));
  if (dasm(av[1]))
    return (1);
  return (0);
}
