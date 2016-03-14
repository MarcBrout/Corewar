/*
** print_list.c for print_list in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Mon Mar 14 11:30:23 2016
** Last update Mon Mar 14 19:13:28 2016 
*/

#include "asm.h"

void			print_list(t_instruc *instruc)
{
  int			i;
  t_list_instruc	*tmp;

  i = 0;
  printf("\n");
  tmp = instruc->root->next;
  while (i < instruc->lenght - 1)
    {
      if (tmp->info->label != NULL)
	printf("label : %s ", tmp->info->label);
      printf("%s %s %s %s\n", tmp->info->name, tmp->info->arg_1, tmp->info->arg_2, tmp->info->arg_3);
      tmp = tmp->next;
      i++;
    }
}
