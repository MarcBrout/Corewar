/*
** list.h for LIST in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 12 17:25:00 2016 bougon_p
** Last update Sat Mar 12 17:25:43 2016 bougon_p
*/

#ifndef LIST_H_
# define LIST_H_

typedef struct		s_cdlist
{
  struct /*ta struct*/	*data;
  struct s_cdlist	*prev;
  struct s_cdlist	*next;
}			t_cdlist;

typedef struct		s_arglist
{
  int			length;
  t_cdlist		*root;
}			t_arglist;

int	create_cdlist(t_arglist *, void *);
int	add_first_cdl(t_arglist *, void *);
int	add_last_cdl(t_arglist *, void *);
int	free_list(t_arglist *);

#endif /* !LIST_H_ */
