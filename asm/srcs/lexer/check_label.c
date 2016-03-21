/*
** check_label.c for ckeck_label in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Wed Mar 16 11:03:52 2016
** Last update Mon Mar 21 22:45:10 2016 marel_m
*/

#include "asm.h"

char	*check_empty_label(t_instruc *instruc, char *new, int fd)
{
  while ((new = get_next_line(fd)) != NULL && my_strlen(new) == 0)
    free(new);
  if ((new = epure_file_instruc(new, 0)) == NULL)
    return (NULL);
  if (my_strlen(new) == 0)
    {
      check_empty_label(instruc, new, fd);
      return (0);
    }
  else
    return (new);
}

int	check_instruc_label(t_instruc *instruc, t_list_instruc *elem,
			    char *new, int fd)
{
  int	i;

  i = -1;
  while (new && new[++i] != '\0' && new[i] != LABEL_CHAR)
    if (check_char(new[i]) == -1)
      return (-1);
  if (new[i] == LABEL_CHAR)
    {
      elem->info->label = my_strndup(new, i + 1);
      if ((new = epure_file_instruc(new, my_strlen(elem->info->label))) == NULL
	  || ((my_strlen(new) == 0
	       && (new = check_empty_label(instruc, new, fd)) == NULL))
	  || check_which_instruc(instruc, elem, new, fd) == -1)
	return (-1);
      free(new);
      return (0);
    }
  return (-1);
}
