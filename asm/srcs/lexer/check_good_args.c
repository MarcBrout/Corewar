/*
** check_good_args.c for check_good_args.c in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar 13 15:47:40 2016
** Last update Mon Mar 14 12:01:00 2016 
*/

#include "asm.h"

int	check_if_label(t_list_instruc *elem, char *file, int i)
{
  if (file[i] != LABEL_CHAR)
    return (-1);
  i++;
  while ((file[i] != ' ' || file[i] != '\t' || file[i] != ',')
	 && file[i] != '\0')
    {
      if (check_char(file[i]) == -1)
	{
	  printf("%c\n", file[i]);
	  return (-1);
	}
      i++;
    }
  return (0);
}

int	check_if_val(t_list_instruc *elem, char *file, int i)
{
  while ((file[i] != ' ' || file[i] != '\t' || file[i] != ',')
	 && file[i] != '\0')
    {
      if (file[i] < '0' || file[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

int	check_direct_arg(t_list_instruc *elem, char *file, int pos)
{
  int	i;
  char	*arg;

  i = 0;
  while (file[i] != ' ' && file[i] != ',' && file[i] != '\t'
	 && file[i] != '\0')
    i++;
  if ((arg = malloc(sizeof(char) * (i + 1))) == NULL)
    return (malloc_fail(), -1);
  arg = my_strncpy(arg, file, i);
  if (arg[0] != DIRECT_CHAR)
    return (-1);
  if (check_if_label(elem, arg, 1) == -1
      && check_if_val(elem, arg, 1) == -1)
    return (-1);
  if (stock_args(elem, arg, pos) == -1)
    return (-1);
  return (0);
}

int	check_indirect_arg(t_list_instruc *elem, char *file, int pos)
{
  int	i;
  char	*arg;

  i = 0;
  while (file[i] != ' ' && file[i] != ',' && file[i] != '\t'
	 && file[i] != '\0')
    i++;
  if ((arg = malloc(sizeof(char) * (i + 1))) == NULL)
    return (malloc_fail(), -1);
  arg = my_strncpy(arg, file, i);
  if (check_if_label(elem, arg, 0) == -1
      && check_if_val(elem, arg, 0) == -1)
    return (-1);
  if (stock_args(elem, arg, pos) == -1)
    return (-1);
  return (0);
}

int	check_registre_arg(t_list_instruc *elem, char *file, int pos)
{
  int	i;
  char	*arg;
  int	nb;
  int	j;

  i = 0;
  while (file[i] != ' ' && file[i] != ',' && file[i] != '\t'
	 && file[i] != '\0')
    i++;
  if ((arg = malloc(sizeof(char) * (i + 1))) == NULL)
    return (malloc_fail(), -1);
  arg = my_strncpy(arg, file, i);
  file = malloc(sizeof(char) * my_strlen(arg));
  i = 1;
  j = 0;
  while (arg[i] != ' ' && arg[i] != ',' && arg[i] != '\t'
	 && arg[i] != '\0')
    {
      file[j] = arg[i];
      j++;
      i++;
    }
  file[j] = '\0';
  nb = atoi(file);
  if (nb < 1 || nb > 16)
    return (-1);
  if (stock_args(elem, arg, pos) == -1)
    return (-1);
  return (0);
}
