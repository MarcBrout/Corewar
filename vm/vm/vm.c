
/*
** vm.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 14:45:48 2016 marc brout
** Last update Mon Mar 21 17:49:50 2016 marc brout
*/

#include "vm.h"

int		my_put_file_str(const char *file,
				const char *str,
				int err)
{
  write(2, file, my_strlen((char *)file));
  wrtie(2, str, my_strlen((char *)str));
  return (err);
}

int		my_put_file_noaccess(const char *file,
				     int err)
{
  write(2, "File ", 5);
  write(2, file, my_strlen((char *)file));
  wrtie(2, " not accessible\n", 16);
  return (err);
}

int		my_put_error(const char *str,
			     int err)
{
  write(2, str, my_strlen((char *)str));
  return (err);
}

int		my_put_usage(char **av, int err)
{
  write(2, "USAGE : ", 8);
  write(2, av[0], my_strlen(av[0]));
  write(2, " [-dump nbr_cycle] [[-n prog_number] \
[-a load_address ] prog_name ...\n", 70);
  return (err);
}

int		main(int ac, char **av)
{
  if (ac < 2)
    my_put_usage(av, 1);
  return (0);
}
