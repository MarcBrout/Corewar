/*
** check_verif_args.c for check_verif_args in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar 13 11:45:19 2016
** Last update Mon Mar 14 10:50:47 2016 
*/

#include "asm.h"

int	verif_one_arg(t_instruc *instruc, t_list_instruc *elem,
		      char *file, int i)
{
  printf("%s -> %s\n", elem->info->name, file);
  if (i == 0 || i == 14 || i == 11 || i == 8)
    check_direct_arg(elem, file, 1);
  else if (i == 15)
    check_registre_arg(elem, file, 1);
  return (0);
}

int	verif_two_args(t_instruc *instruc, t_list_instruc *elem,
		       char *file, int i)
{
  char	*new;

  printf("%s -> %s\n", elem->info->name, file);
  if (i == 1 || i == 12)
    {
      if (check_direct_arg(elem, file, 1) == -1
	  && check_indirect_arg(elem, file, 1) == -1)
	return (-1);
      if ((new = epure_file_instruc(file,
				    my_strlen(elem->info->arg_1))) == NULL)
	return (-1);
      if (check_registre_arg(elem, new, 2) == -1)
	return (-1);
    }
  else if (i == 2)
    {
      if (check_registre_arg(elem, file, 1) == -1)
	return (-1);
      if ((new = epure_file_instruc(file,
				    my_strlen(elem->info->arg_1))) == NULL)
	return (-1);
      if (check_indirect_arg(elem, new, 2) == -1
	  && check_registre_arg(elem, new, 2) == -1)
	return (-1);
    }
  return (0);
}
int	verif_three_args(t_instruc *instruc, t_list_instruc *elem,
			 char *file, int i)
{
  char	*new;
  printf("%s -> %s\n", elem->info->name, file);
  if (i == 3 || i == 4)
    {
      if (check_registre_arg(elem, file, 1) == -1)
	return (-1);
      if ((new = epure_file_instruc(file,
				    my_strlen(elem->info->arg_1))) == NULL)
	return (-1);
      if (check_registre_arg(elem, new, 2) == -1)
	return (-1);
      if ((new = epure_file_instruc(new,
				    my_strlen(elem->info->arg_2))) == NULL)
	return (-1);
      if (check_registre_arg(elem, new, 3) == -1)
	return (-1);
    }
  return (0);
}

int	check_stock_good_args(t_instruc *instruc, t_list_instruc *elem,
			      char *file, int i)
{
  char	*new;
  int	j;
  int	l;

  j = my_strlen(elem->info->name);
  new = malloc(sizeof(char) * (my_strlen(file) - j + 1));
  l = 0;
  while (file[j] != '\0')
    new[l++] = file[j++];
  new[l] = '\0';
  if ((new = epure_file_instruc(new, 0)) == NULL)
    return (-1);
  if (op_tab[i].nbr_args == 3)
    verif_three_args(instruc, elem, new, i);
  else if (op_tab[i].nbr_args == 2)
    verif_two_args(instruc, elem, new, i);
  else
    verif_one_arg(instruc, elem, new, i);
  return (0);
}
