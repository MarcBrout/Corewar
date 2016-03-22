/*
** check_good_args.c for check_good_args.c in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar 13 15:47:40 2016
** Last update Tue Mar 22 15:15:10 2016 marel_m
*/

#include "asm.h"

int		check_if_label(t_instruc *instruc, char *file, int i)
{
  t_list_label	*new;

  if (file[i] != LABEL_CHAR)
    return (-1);
  i++;
  while ((file[i] != ' ' || file[i] != '\t' || file[i] != ',')
	 && file[i] != '\0')
    {
      if (check_char(file[i]) == -1)
	return (-1);
      i++;
    }
  if ((new = add_list_after_label(instruc)) == NULL)
    return (-1);
  new->name = my_strdup(file);
  new->pos = instruc->nb_l;
  return (0);
}

int	check_if_val(char *file, int i)
{
  if (file[i] < '0' && file[i] > '9' && file[i] != '-')
    return (-1);
  i++;
  while ((file[i] != ' ' || file[i] != '\t' || file[i] != ',')
	 && file[i] != '\0')
    {
      if (file[i] < '0' || file[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

int	check_direct_arg(t_instruc *instruc, t_list_instruc *elem,
			 char *file, int pos)
{
  int	i;
  char	*arg;

  i = 0;
  while (file[i] != ' ' && file[i] != ',' && file[i] != '\t'
	 && file[i] != '\0')
    i++;
  if ((arg = my_strndup(file, i)) == NULL)
    return (-1);
  if (arg[0] != DIRECT_CHAR
      || (check_if_label(instruc, arg, 1) == -1
	  && check_if_val(arg, 1) == -1)
      || stock_args(elem, arg, pos) == -1)
    return (-1);
  return (0);
}

int	check_indirect_arg(t_instruc *instruc, t_list_instruc *elem,
			   char *file, int pos)
{
  int	i;
  char	*arg;

  i = 0;
  while (file[i] != ' ' && file[i] != ',' && file[i] != '\t'
	 && file[i] != '\0')
    i++;
  if ((arg = my_strndup(file, i)) == NULL)
    return (-1);
  if ((check_if_label(instruc, arg, 0) == -1
       && check_if_val(arg, 0) == -1)
      || stock_args(elem, arg, pos) == -1)
    return (-1);
  return (0);
}

int	check_registre_arg(t_list_instruc *elem, char *file, int pos)
{
  int	i;
  int	nb;
  int	j;
  char	*arg;

  i = 0;
  while (file[i] != ' ' && file[i] != ',' && file[i] != '\t'
	 && file[i] != '\0')
    i++;
  if ((arg = my_strndup(file, i)) == NULL)
    return (-1);
  if ((file = malloc(sizeof(char) * my_strlen(arg))) == NULL)
    return (malloc_fail(), -1);
  i = 1;
  j = 0;
  while (arg[i] != ' ' && arg[i] != ',' && arg[i] != '\t'
	 && arg[i] != '\0')
    file[j++] = arg[i++];
  file[j] = '\0';
  nb = atoi(file);
  if (nb < 1 || nb > 16 || stock_args(elem, arg, pos) == -1)
    return (-1);
  free(file);
  return (0);
}
