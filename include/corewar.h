/*
** corewar.h for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Mar 15 19:05:26 2016 marc brout
** Last update Tue Mar 15 19:54:13 2016 marc brout
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# include "op.h"

typedef struct		s_champion
{
  char			*name;
  int			nb;
  int			dump;
  int			start;
  struct s_champion	*next;
}			t_champion;

typedef struct		s_arena
{
  t_champion		*champions;
  int			dump;
}			t_arena;

#endif /* !COREWAR_H_ */
