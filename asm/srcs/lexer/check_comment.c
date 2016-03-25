/*
** check_comment.c for check_comment in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 17:20:59 2016
** Last update Fri Mar 25 14:24:33 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "asm.h"

int	check_double_quote_comment(char *file)
{
  int   i;

  if (file[0] != '"')
    return (-1);
  i = 1;
  while (file[i] != '"')
    i++;
  if (i != (my_strlen(file) - 1) || i > 2050)
    return (-1);
  return (0);
}

void	no_comment(t_header *header)
{
  header->comment[0] = '\0';
  write(1, "warning: no comment specified\n", 30);
}

void	stock_comment(t_header *header, char *file)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (++i != (my_strlen(file) - 1))
    header->comment[j++] = file[i];
  header->comment[j] = '\0';
}

int	check_comment(t_header *header, t_instruc *instruc, char *file)
{
  char	*new;

  if ((new = epure_file_name_com(file, 0)) == NULL)
    return (-1);
  if (my_strncmp(new, ".comment", 8) != 0
      || (new[8] != ' ' && new[8] != '\t'))
    {
      if (my_strncmp(new, ".name", 5) == 0)
	return (write(2, "Name can only be defined once.\n", 31), -1);
      no_comment(header);
      return (free(new), 1);
    }
  free(new);
  instruc->nb_l++;
  if ((new = epure_file_name_com(file, 9)) == NULL)
    return (-1);
  if (check_double_quote_comment(new) == -1)
    return (synthax_error(instruc, 0), -1);
  stock_comment(header, new);
  free(new);
  return (0);
}
