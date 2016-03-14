/*
** check_instructions.c for check_instructions in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/lexer
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 18:05:32 2016
** Last update Mon Mar 14 19:21:54 2016 
*/

#include "asm.h"

int	check_instruc_label(t_instruc *instruc, t_list_instruc *elem, char *new)
{
  int	i;

  i = 0;
  while (new && new[i] != '\0' && new[i] != LABEL_CHAR)
    {
      if (check_char(new[i]) == -1)
	return (-1);
      i++;
    }
  if (new[i] == LABEL_CHAR)
    {
      if ((elem->info->label = malloc(sizeof(char) * (i + 2))) == NULL)
	return (-1);
      elem->info->label = my_strncpy(elem->info->label, new, i + 1);
      if ((new = epure_file_instruc(new, my_strlen(elem->info->label))) == NULL)
      	return (-1);
      if (check_which_instruc(instruc, elem, new) == -1)
      	return (-1);
      return (0);
    }
  return (-1);
}

int	check_which_instruc(t_instruc *instruc, t_list_instruc *elem, char *file)
{
  int	i;

  i = -1;
  while (++i < 16)
    if (my_strncmp(file,
		   op_tab[i].mnemonique, my_strlen(op_tab[i].mnemonique)) == 0
	&& file[my_strlen(op_tab[i].mnemonique)] == ' ')
      {
	elem->info->name = malloc(sizeof(char) * (my_strlen(op_tab[i].mnemonique) + 1));
	elem->info->name = my_strcpy(elem->info->name, op_tab[i].mnemonique);
	if (check_stock_good_args(instruc, elem, file, i) == -1)
	  return (-1);
	return (0);
      }
  if (elem->info->label == NULL)
    if (check_instruc_label(instruc, elem,file) == -1)
      return (-1);
  return (0);
}

int			check_instruc_arg(t_instruc *instruc, char *file)
{
  char			*new;
  t_list_instruc	*elem;

  if ((elem = add_list_after(instruc)) == NULL)
    return (-1);
  if ((elem->info = malloc(sizeof(t_info))) == NULL)
    return (-1);
  elem->info->name = NULL;
  elem->info->arg_1 = NULL;
  elem->info->arg_2 = NULL;
  elem->info->arg_3 = NULL;
  elem->info->label = NULL;
  if ((new = epure_file_instruc(file, 0)) == NULL)
    return (-1);
  if (check_which_instruc(instruc, elem, new) == -1)
    return (-1);
  return (0);
}

int	put_instruc(t_instruc *instruc, int fd)
{
  char	*file;

  while ((file = get_next_line(fd)) != NULL && my_strlen(file) == 0);
  if (file != NULL)
    {
      if (check_instruc_arg(instruc, file) == -1)
	return (-1);
      put_instruc(instruc, fd);
    }
  return (0);
}

int	check_instructions(t_instruc *instruc, int fd)
{
  if (create_list(instruc) == -1)
    return (-1);
  put_instruc(instruc, fd);
  print_list(instruc);
  return (0);
}
