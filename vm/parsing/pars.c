/*
** pars.c for pars in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 12:58:17 2016 benjamin duhieu
** Last update Mon Mar 21 13:46:45 2016 benjamin duhieu
*/

#include "pars.h"

int		main(int argc, char **argv)
{
  t_pars	*arg;
  t_data	data;
  int		i;

  if (argc < 2 || !argv)
    my_puterror("Usage : corewar [-dump nbr_cycle] [[-n prog_number] \
[-a load_address ] prog_name]", 1);
  if (!(arg = init_list()))
    return (1);
  i = 0;
  while (argv[i])
    if (check_arg(argv, &i, arg, &data))
      return (1);
}
