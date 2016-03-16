/*
** check_instructions.c for check_instructions in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/lexer
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 18:05:32 2016
** Last update Wed Mar 16 11:04:29 2016 
*/

#include "asm.h"

int	check_which_instruc(t_instruc *instruc, t_list_instruc *elem,
			    char *file, int fd)
{
  int	i;

  i = -1;
  while (++i < 16)
    if (my_strncmp(file,
		   op_tab[i].mnemonique, my_strlen(op_tab[i].mnemonique)) == 0
	&& file[my_strlen(op_tab[i].mnemonique)] == ' ')
      {
	elem->info->name = my_strdup(op_tab[i].mnemonique);
	if (check_stock_good_args(instruc, elem, file, i) == -1)
	  return (-1);
	return (0);
      }
  if (elem->info->label == NULL)
    if (check_instruc_label(instruc, elem, file, fd) == -1)
      return (-1);
  return (0);
}

int			check_instruc_arg(t_instruc *instruc, char *file, int fd)
{
  char			*new;
  t_list_instruc	*elem;

  if ((elem = add_list_after(instruc)) == NULL
      || (elem->info = malloc(sizeof(t_info))) == NULL)
    return (-1);
  elem->info->name = NULL;
  elem->info->arg_1 = NULL;
  elem->info->arg_2 = NULL;
  elem->info->arg_3 = NULL;
  elem->info->label = NULL;
  if ((new = epure_file_instruc(file, 0)) == NULL
      || check_which_instruc(instruc, elem, new, fd) == -1)
    return (-1);
  return (0);
}

int	put_instruc(t_instruc *instruc, int fd)
{
  char	*file;

  while ((file = get_next_line(fd)) != NULL && my_strlen(file) == 0);
  if (file != NULL)
    {
      if (check_instruc_arg(instruc, file, fd) == -1)
	return (-1);
      put_instruc(instruc, fd);
    }
  return (0);
}

int	check_instructions(t_instruc *instruc, int fd)
{
  if (create_list(instruc) == -1 || create_list_label(instruc) == -1)
    return (-1);
  put_instruc(instruc, fd);
  return (0);
}
