/*
** put_in_list.c for put_in_list in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 15:43:13 2016
** Last update Sat Mar 12 18:20:53 2016 
*/

#include "asm.h"

int		create_list(t_instruc *instruc)
{
  t_list_instruc	*new;

  if ((new = malloc(sizeof(t_list_instruc))) == NULL)
    return (malloc_fail(), -1);
  new->prev = new;
  new->next = new;
  instruc->root = new;
  return (0);
}

t_list_instruc		*add_list_after(t_list_instruc *root)
{
  t_list_instruc	*new;

  if ((new = malloc(sizeof(t_list_instruc))) == NULL)
    return (malloc_fail(), NULL);
  root->prev->next = new;
  new->prev = root->prev;
  root->prev = new;
  new->next = root;
  return (new);
}

t_list_instruc		*put_after(t_instruc *instruc)
{
  t_list_instruc	*new;

  if ((new = add_list_after(instruc->root)) == NULL)
    return (NULL);
  new->info->name = malloc(sizeof(char) * 8);
  new->info->name = "bonjour";
  new->info->name[7] = '\0';
  return (new);
}
