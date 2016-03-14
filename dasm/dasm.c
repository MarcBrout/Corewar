/*
** dasm.c for corewar in /home/brout_m/RENDU/CPE/CPE_2015_corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 14 10:48:24 2016 marc brout
** Last update Mon Mar 14 11:04:36 2016 marc brout
*/

#include <unistd.h>
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

int	dasm(const char *file)
{

  return (0);
}

int	main(int ac, char **av)
{
  if (ac < 2 || !av[1][0])
    return (my_print_error(USAGE, 1));
  dasm(av[1]);
  return (0);
}
