/*
** check_comment.c for check_comment in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 17:20:59 2016
** Last update Fri Mar 11 17:05:24 2016 
*/

#include "asm.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int	check_double_quote_comment(char *file)
{
  int   i;

  if (file[0] != '"')
    return (-1);
  i = 1;
  while (file[i] != '"')
    i++;
  if (i != (strlen(file) - 1) || i > 2050)
    return (-1);
  return (0);
}

int	check_comment(t_header *header, char *file)
{
  char	*new;
  int	i;
  int	j;

  if ((new = epure_file_name_com(file, 0)) == NULL)
    return (-1);
  if (strncmp(new, ".comment", 8) != 0
      || (new[8] != ' ' && new[8] != '\t'))
    {
      header->comment[0] = '\0';
      write(1, "warning: no comment specified\n", 30);
      return (1);
    }
  if ((new = epure_file_name_com(file, 9)) == NULL)
    return (-1);
  if (check_double_quote_comment(new) == -1)
    {
      header->comment[0] = '\0';
      write(1, "warning: no comment specified\n", 30);
      return (1);
    }
  i = 0;
  j = 0;
  while (++i != (strlen(new) - 1))
    {
      header->comment[j] = new[i];
      j++;
    }
  header->comment[j] = '\0';
  printf("%s\n", header->comment);
  return (0);
}
