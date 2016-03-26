/*
** check_comment.c for check_comment in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 17:20:59 2016
** Last update Sat Mar 26 20:07:10 2016 marel_m
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
  if (i != (my_strlen(file) - 1) || i >= 2049)
    return (-1);
  return (0);
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
  printf("%s\n", header->comment);
}

int	no_comment(t_instruc *instruc, t_header *header, char *new)
{
  header->comment[0] = '\0';
  write(2, "Warning: no comment specified.\n", 31);
  if ((instruc->first_no_c = my_strdup(new)) == NULL)
    return (-1);
  return (0);
}

int	check_comment(t_header *header, t_instruc *instruc,
		      char *file)
{
  char	*new;

  if ((new = epure_file_name_com(file, 0)) == NULL)
    return (-1);
  if (my_strncmp(new, ".comment", 8) != 0
      || (new[8] != ' ' && new[8] != '\t'))
    {
      if (my_strncmp(new, ".name", 5) == 0)
	return (write(2, "Name can only be defined once.\n", 31), -1);
      if (no_comment(instruc, header, new) == -1)
	return (-1);
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

int	put_instruc_no_comm(t_instruc *instruc, int fd)
{
  instruc->nb_l++;
  if (instruc->first_no_c[0] == '#' || instruc->first_no_c[0] == ';'
      || my_strlen(instruc->first_no_c) == 0
      || check_line(instruc->first_no_c) == -1
      || if_comment_text(instruc->first_no_c) == -1)
    {
      if (put_instruc(instruc, fd) == -1)
	return (-1);
    }
  else if (check_instruc_arg(instruc, instruc->first_no_c, fd) == -1
	   || put_instruc(instruc, fd) == -1)
    return (-1);
  free(instruc->first_no_c);
  put_instruc(instruc, fd);
  return (0);
}
