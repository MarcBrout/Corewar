/*
** dasm.c for corewar in /home/brout_m/RENDU/CPE/CPE_2015_corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 14 10:48:24 2016 marc brout
** Last update Tue Mar 15 18:29:49 2016 marc brout
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

char		coding_byte(int fd)
{
  char		cb;

  if (read(fd, &cb, 1) < 1)
    return (-1);
  return (cb);
}

int		swap_integer(int nb)
{
  int		ret;

  ret = ((nb >> 24) & 0xff) | ((nb << 8) & 0xff0000) |
    ((nb >> 8) & 0xff00) | ((nb << 24) & 0xff000000);
  return (ret);
}

int		inst_live(int in, UNUSED int out)
{
  int		player;
  char		*tmp;

  if (read(in, &player, 4) < 4)
    return (1);
  player = 123123;
  tmp = setnbr(player);
  my_printf("%s\n", tmp);
  return (0);
}

int		inst_sti(int in, UNUSED int out)
{
  char		cb;

  if ((cb = coding_byte(in)) < 0)

}

int		prog_name_comment(int out, t_header *head)
{
  if (write(out, "\t.name \"", 8) < 0 ||
      write(out, head->prog_name, my_strlen(head->prog_name)) < 0 ||
      write(out, "\"\n", 2) < 0 ||
      write(out, "\t.name \"", 8) < 0 ||
      write(out, head->comment, my_strlen(head->comment)) < 0 ||
      write(out, "\"\n\n", 3) < 0)
    return (1);
  return (0);
}

int		dasm(const char *file)
{
  int		fd;
  int		out;
  t_header	head;

  if ((fd = open(file, O_RDONLY)) < 0 ||
      (read(fd, &head, sizeof(t_header))) < (int)sizeof(t_header))
    return (1);
  my_printf("magic = %x\nProg_name = %s\nProg_size = %d\ncomment = %s\n",
	    head.magic, head.prog_name, head.prog_size / 8, head.comment);
  printf("%x, %x\n", (unsigned int)head.magic, COREWAR_EXEC_MAGIC);
  if (test_endianness())
    head.magic = swap_integer(head.magic);
  if ((head.magic != COREWAR_EXEC_MAGIC) || (!head.prog_size))
    return (1);
  if ((out = open("./test.s", O_CREAT | O_WRONLY,
		  S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH)) < 0)
    return (1);
  prog_name_comment(out, &head);
  inst_live(fd, out);
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
