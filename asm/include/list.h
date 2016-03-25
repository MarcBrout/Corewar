/*
** list.h for LIST in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 23 22:47:58 2016 bougon_p
** Last update Thu Mar 24 01:58:42 2016 bougon_p
*/

#ifndef LIST_H_
# define LIST_H_

# include <stdbool.h>

typedef	struct		s_lablist
{
  char			*name;
  int			addr;
  int			nb_bytes;
  bool			zjmp;
}			t_lablist;

typedef struct          s_cdlist
{
  struct s_lablist	*data;
  struct s_cdlist       *prev;
  struct s_cdlist       *next;
}                       t_cdlist;

typedef struct          s_arglist
{
  t_cdlist              *root;
}                       t_arglist;

int     create_cdlist(t_cdlist *, void *);
int     add_last_cdl(t_cdlist *, void *);
int     free_lablist(t_arglist *);

#endif /* !LIST_H_ */
