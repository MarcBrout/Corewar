/*
** epure_file.c for epure_file in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 17:04:35 2016
** Last update Mon Mar 14 22:11:57 2016 
*/

#include "asm.h"

char	*epure_file_name_com(char *file, int i)
{
  int	j;
  char	*new;

  while (file && (file[i] == ' ' || file[i] == '\t') && file[i])
    i++;
  if ((new = malloc(sizeof(char) * (my_strlen(file) - i + 1))) == NULL)
    return (malloc_fail(), NULL);
  j = 0;
  while (file[i] != '\0')
    {
      new[j] = file[i];
      i++;
      j++;
    }
  new[j] = '\0';
  return (new);
}

char	*epure_file_instruc(char *file, int i)
{
  int	j;
  char	*new;

  while (file && (file[i] == ' '
		  || file[i] == '\t' || file[i] == ',') && file[i])
    i++;
  if ((new = malloc(sizeof(char) * (my_strlen(file) - i + 1))) == NULL)
    return (malloc_fail(), NULL);
  j = 0;
  while (file[i] != '\0')
    {
      new[j] = file[i];
      i++;
      j++;
    }
  new[j] = '\0';
  return (new);
}

int	check_end_instruc(char *file, int i)
{
  while (file && file[i] != '\0')
    {
      if (file[i] != ' ' && file[i] != '\t' && file[i] != ',')
	return (-1);
      i++;
    }
  return (0);
}
