/*
** load_file.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 12:07:50 2016 marc brout
** Last update Mon Mar 21 12:11:02 2016 marc brout
*/

#include "load.h"

int	load_champion(const char *champion)
{
  int	fd;

  if ((fd = open(champion, O_RDONLY)) < 0)
    return (1);
  return (0);
}

int	main(int ac, char **av)
{
  load_champion(av[1]);
  return (0);
}
