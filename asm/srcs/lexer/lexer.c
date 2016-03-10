/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/parser
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 15:41:48 2016
** Last update Thu Mar 10 16:15:20 2016 
*/

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*new_file(char *file)
{
  int	i;
  int	j;
  char	*new;

  i = 0;
  while (file && (file[i] == ' ' || file[i] == '\t') && file[i])
    i++;
  j = 0;
  if ((new = malloc(sizeof(char) * strlen(file) - i + 1)) == NULL)
    return (NULL);
  while (file[i] != '\0')
    {
      new[j] = file[i];
      i++;
      j++;
    }
  new[j] = '\0';
  return (new);
}

int	check_name(t_header *header, char *file)
{
  char	*new;
  int	i;
  int	j;

  if ((new = new_file(file)) == NULL)
    return (-1);
  if (strncmp(new, ".name ", 6) != 0)
    {
      write(2, "wrong .name\n", 12);
      return (-1);
    }
  i = 6;
  j = 0;
  while (new[++i] != '\0')
    {
      header->prog_name[j] = new[i];
      j++;
    }
  printf("%s\n", header->prog_name);
  return (-1);
}

int	check_s(t_header *header, char *str)
{
  int	fd;
  char	*file;

  if ((fd = open(str, O_RDONLY)) == -1)
    return (-1);
  while ((file = get_next_line(fd)) != NULL)
    {
      if (check_name(header, file) == -1)
	return (-1);
    }
  return (0);
}

int	main(int ac, char **av)
{
  t_header	header;

  if (ac != 2)
    {
      write(2, "Wrong arguments\n", 16);
      return (-1);
    }
  check_s(&header, av[1]);
}
