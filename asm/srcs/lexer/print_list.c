/*
** print_list.c for print_list in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Mon Mar 14 11:30:23 2016
** Last update Wed Mar 16 10:30:55 2016 
*/

#include "asm.h"

void		print_list_label(t_instruc *instruc)
{
  t_list_label	*tmp;
  int		i;

  i = 0;
  printf("\nLabel:\n");
  tmp = instruc->lab->next;
  while (i < instruc->lenght_label - 1)
    {
      printf("%s\n", tmp->name);
      tmp = tmp->next;
      i++;
    }
}

void			print_list(t_header *header, t_instruc *instruc)
{
  int			i;
  t_list_instruc	*tmp;

  i = 0;
  printf("%s\n%s\n\n", header->prog_name, header->comment);
  tmp = instruc->root->next;
  while (i < instruc->lenght - 1)
    {
      if (tmp->info->label != NULL)
	printf("label : %s ", tmp->info->label);
      printf("%s %s %s %s\n", tmp->info->name, tmp->info->arg_1, tmp->info->arg_2, tmp->info->arg_3);
      tmp = tmp->next;
      i++;
    }
  print_list_label(instruc);
}
