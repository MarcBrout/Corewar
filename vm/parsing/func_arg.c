/*
** func_arg.c for func in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 13:29:10 2016 benjamin duhieu
** Last update Mon Mar 21 14:14:03 2016 benjamin duhieu
*/

#include "pars.h"

int	chk_dump(char **av, int *i, t_data *data)
{
  int	res;

  if (!(my_strcmp(av[*i + 1], "-a")) || !(my_strcmp(av[*i + 1], "-n")))
    {
      data->dump = 0;
      *i += 1;
      return (0);
    }
  if (!(res = my_getnbr_prog(av[*i + 1])) || res > CYCLE_TO_DIE)
    return (1);
  data->dump = res;
  *i += 2;
  return (0);
}

int	chk_adress(char **av, int *i, t_data *data)
{
  return (0);
}

int	chk_prog_nbr(char **av, int *i, t_data *data)
{
  return (0);
}

int		check_arg(char **av, int *i, t_pars *arg, t_data *dat)
{
  t_pars	*elem;

  elem = arg->next;
  while (elem != NULL)
    {
      if (!(my_strcmp(av[*i], elem->arg, dat)))
	{
	  elem->arg(av, i);
	  return (0);
	}
      elem = elem->next;
    }

  return (1);
}
