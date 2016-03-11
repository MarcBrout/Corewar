/*
** check_comment.c for check_comment in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 17:20:59 2016
** Last update Fri Mar 11 13:42:53 2016 
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

char	*epure_file_comment(char *file, int i)
{
  int	j;
  char	*new;

  while (file && (file[i] == ' ' || file[i] == '\t') && file[i])
    i++;
  j = 0;
  if ((new = malloc(sizeof(char) * strlen(file) - i + 1)) == NULL)
    {
      return (NULL);
    }
  while (file[i] != '\0')
    {
      new[j] = file[i];
      i++;
      j++;
    }
  new[j] = '\0';
  return (new);
}

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

  if ((new = epure_file_comment(file, 0)) == NULL)
    return (-1);
  if (strncmp(new, ".comment", 8) != 0
      || (new[8] != ' ' && new[8] != '\t'))
    {
      write(1, "warning: no comment specified\n", 30);
      return (1);
    }
  if ((new = epure_file_comment(file, 9)) == NULL)
    return (-1);
  if (check_double_quote_comment(new) == -1)
    {
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
