/*
** pars.h for pars in /home/duhieu_b/CPE/CPE_2015_corewar/vm/include
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 12:49:06 2016 benjamin duhieu
** Last update Mon Mar 21 14:06:22 2016 benjamin duhieu
*/

#ifndef PARS_H_
# define PARS_H_

# include "load.h"

typedef struct	s_data
{
  int		dump;
  t_champion	champ[4];
}		t_data;

typedef struct	s_pars
{
  char		*arg;
  int		(*chk_arg)(char **, int *, t_data *);
  struct s_pars	*next;
}		t_pars;

#endif /* !PARS_H_ */
