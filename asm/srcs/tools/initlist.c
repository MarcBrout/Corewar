/*
** initlist.c for LIST in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 12 17:25:14 2016 bougon_p
** Last update Sat Mar 12 17:25:24 2016 bougon_p
*/

#include "tetris.h"

int		create_cdlist(t_arglist *arg, void *_data)
{
  t_cdlist	*elem;

  if ((elem = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  arg->root = elem;
  elem->prev = arg->root;
  elem->next = arg->root;
  elem->data = _data;
  arg->length = 1;
  return (0);
}

int		add_first_cdl(t_arglist *arg, void *_data)
{
  t_cdlist	*elem;

  if ((elem = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  if (arg->root != NULL)
    {
      elem->prev = arg->root;
      elem->next = arg->root->next;
      arg->root->next->prev = elem;
      arg->root->next = elem;
    }
  elem->data = _data;
  arg->length++;
  return (0);
}

int	add_last_cdl(t_arglist *arg, void *_data)
{
  t_cdlist	*elem;

  if ((elem = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  if (arg->root != NULL)
    {
      elem->prev = arg->root->prev;
      elem->next = arg->root;
      arg->root->prev->next = elem;
      arg->root->prev = elem;
    }
  elem->data = _data;
  arg->length++;
  return (0);
}

int		free_list(t_arglist *arg)
{
  int		i;
  t_cdlist	*tmp;
  t_cdlist	*tmp2;

  i = 0;
  tmp2 = arg->root;
  while (i < arg->length)
    {
      tmp = tmp2;
      tmp2 = tmp->next;
      free(tmp->data);
      free(tmp);
      i++;
    }
  return (0);
}
