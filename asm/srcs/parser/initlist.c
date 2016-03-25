/*
** initlist.c for LIST in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 23 22:24:42 2016 bougon_p
** Last update Thu Mar 24 00:38:59 2016 bougon_p
*/

#include "asm.h"

void		debug_lists(t_instruc *instruc)
{
  t_cdlist	*tmp;

  /*
  ** CALL TO LABS
  */

  tmp = instruc->call_to_lab.root->next;
  while (tmp != instruc->call_to_lab.root)
    {
      printf("\n###NOUVEAU MAILLON __ CALL_TO __###\n");
      printf("NAME = %s\n", tmp->data->name);
      printf("ADDR = %d\n", tmp->data->addr);
      printf("NB BYTES = %d\n\n", tmp->data->nb_bytes);
      tmp = tmp->next;
    }

  /*
  ** REAL LABS
  */

  tmp = instruc->real_lab.root->next;
  while (tmp != instruc->real_lab.root)
    {
      printf("\n###NOUVEAU MAILLON __ REAL __###\n");
      printf("NAME = %s\n", tmp->data->name);
      printf("ADDR = %d\n", tmp->data->addr);
      printf("NB BYTES = %d\n\n", tmp->data->nb_bytes);
      tmp = tmp->next;
    }
}

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
