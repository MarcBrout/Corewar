/*
** check_name.c for check_name in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 17:09:07 2016
** Last update Fri Mar 11 14:16:23 2016 
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

char	*epure_file_name(char *file, int i)
{
  int	j;
  char	*new;

  while (file && (file[i] == ' ' || file[i] == '\t') && file[i])
    i++;
  j = 0;
  if ((new = malloc(sizeof(char) * strlen(file) - i + 1)) == NULL)
    return (malloc_fail(), NULL);
  while (file[i] != '\0')
    {
      new[j] = file[i];
      i++;
      j++;
    }
  new[j] = '\0';
  return (new);
}

int	check_double_quote_name(char *file)
{
  int	i;

  if (file[0] != '"')
    return (-1);
  i = 1;
  while (file[i] != '"')
    i++;
  if (i != (strlen(file) - 1) || i > 130)
    return (-1);
  return (0);
}

int	check_name(t_header *header, char *file)
{
  char	*new;
  int	i;
  int	j;

  if ((new = epure_file_name(file, 0)) == NULL)
    return (-1);
  if (strncmp(new, ".name", 5) != 0
      || (new[5] != ' ' && new[5] != '\t'))
    {
      write(2, "wrong .name\n", 12);
      return (-1);
    }
  if ((new = epure_file_name(file, 6)) == NULL)
    return (-1);
  if (check_double_quote_name(new) == -1)
    {
      write(2, "wrong .name\n", 12);
      return (-1);
    }
  i = 0;
  j = 0;
  while (++i != (strlen(new) - 1))
    {
      header->prog_name[j] = new[i];
      j++;
    }
  header->prog_name[j] = '\0';
  printf("%s\n", header->prog_name);
  return (0);
}
