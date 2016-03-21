/*
** pars.c for pars in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 12:58:17 2016 benjamin duhieu
** Last update Mon Mar 21 16:34:24 2016 benjamin duhieu
*/

#include "pars.h"

int		my_put_error(char *str, int err)
{
  write(2, "prog number ", 12);
  write(2, str, my_strlen(str));
  write(2, " already used\n", 14);
  return (err);
}

int		main(int argc, char **argv)
{
  t_pars	*arg;
  t_data	data;
  int		i;
  int		chk;

  if (argc < 2 || !argv)
    return (my_put_usage(argv, 2));
  data.place_champ = 0;
  if (!(arg = init_list()))
    return (1);
  i = 0;
  while (argv[i])
    {
      if ((chk = check_arg(argv, &i, arg, &data)) == 1)
	return (my_put_usage(argv, 1));
      else if (chk == 2)
	{
	  if (load_champion[&data->champion[data->place_champ], av[*i]))
	    data->valide = 0;
	}
      else if (chk == 3)
	return (1);
    }
}
