/*
** check_instructions.c for check_instructions in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/lexer
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 18:05:32 2016
** Last update Sun Mar 13 19:03:15 2016 
*/

#include "asm.h"

int	check_instruc_label(char *new)
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
      printf("label -> %s\n", new);
      return (0);
    }
  return (-1);
}

int			check_instruc_arg(t_instruc *instruc, char *file)
{
  char			*new;
  int			i;
  t_list_instruc	*elem;

  if ((elem = add_list_after(instruc)) == NULL)
    return (-1);
  if ((elem->info = malloc(sizeof(t_info))) == NULL)
    return (-1);
  if ((new = epure_file_instruc(file, 0)) == NULL)
    return (-1);
  i = -1;
  while (++i < 16)
    if (my_strncmp(new,
		   op_tab[i].mnemonique, my_strlen(op_tab[i].mnemonique)) == 0
	&& new[my_strlen(op_tab[i].mnemonique)] == ' ')
      {
	elem->info->name = malloc(sizeof(char) * (my_strlen(op_tab[i].mnemonique) + 1));
	elem->info->name = my_strcpy(elem->info->name, op_tab[i].mnemonique);
	check_stock_good_args(instruc, elem, new, i);
	return (0);
      }
  if (check_instruc_label(new) == -1)
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
  return (0);
}
