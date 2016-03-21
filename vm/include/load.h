/*
** load.h for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 12:58:44 2016 marc brout
** Last update Mon Mar 21 14:03:57 2016 marc brout
*/

#ifndef LOAD_H_
# define LOAD_H_

#include "op.h"

typedef	struct		s_pc
{
  unsigned int		pc;
  struct s_pc		*next;
}			t_pc;

typedef struct		s_champion
{
  char			valid;
  char			alive;
  int			order;
  char			name[PROG_NAME_LENGTH + 1];
  t_pc			*pc;
}			t_champion;

#endif /* !LOAD_H_ */
