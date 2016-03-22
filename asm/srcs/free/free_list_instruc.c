/*
** free_list_instruc.c for free_list_instruc in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs
**
** Made by Marel la plus belle <3
** Login   <marel_m@epitech.net>
**
** Started on  Mon Mar 21 18:09:15 2016 Marel la plus belle <3
** Last update Mon Mar 21 19:45:29 2016 Marel la plus belle <3
*/

#include "asm.h"

void	free_info_instruc(t_info *info)
{
  free(info->name);
  free(info->arg_1);
  free(info->arg_2);
  free(info->arg_3);
  free(info->label);
}

void			free_list_instruc(t_instruc *instruc)
{
  int			i;
  t_list_instruc	*tmp;
  t_list_instruc	*tmp2;

  i = 0;
  tmp2 = instruc->root->next;
  while (i < instruc->lenght - 1)
    {
      tmp = tmp2;
      tmp2 = tmp->next;
      free_info_instruc(tmp->info);
      free(tmp->info);
      free(tmp);
      i++;
    }
  free(instruc->root);
}

void		free_list_label(t_instruc *instruc)
{
  int		i;
  t_list_label	*tmp;
  t_list_label	*tmp2;

  i = 0;
  tmp2 = instruc->lab->next;
  while (i < instruc->lenght_label - 1)
    {
      tmp = tmp2;
      tmp2 = tmp->next;
      free(tmp->name);
      free(tmp);
      i++;
    }
  free(instruc->lab);
}

void	free_list(t_instruc *instruc)
{
  free_list_instruc(instruc);
  free_list_label(instruc);
}