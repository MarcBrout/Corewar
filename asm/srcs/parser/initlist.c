/*
** initlist.c for LIST in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 23 22:24:42 2016 bougon_p
** Last update Fri Mar 25 15:45:49 2016 bougon_p
*/

#include "asm.h"

int		create_labcdlist(t_cdlist **root)
{
  t_cdlist	*elem;

  if ((elem = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  *root = elem;
  elem->prev = *root;
  elem->next = *root;
  return (0);
}

int		add_last_labcdl(t_cdlist *root, void *_data)
{
  t_cdlist	*elem;

  if ((elem = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  if (root != NULL)
    {
      elem->prev = root->prev;
      elem->next = root;
      root->prev->next = elem;
      root->prev = elem;
    }
  elem->data = _data;
  return (0);
}

int		free_lablist(t_arglist *arg)
{
  int		i;
  t_cdlist	*tmp;

  i = 0;
  tmp = arg->root->next;
  while (tmp != arg->root)
    {
      i++;
      tmp = tmp->next;
    }
  return (0);
}
