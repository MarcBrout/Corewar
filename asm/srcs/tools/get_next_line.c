/*
** get_next_line.c for GETNEXTLINE in /CPE_2015_getnextline
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar  8 10:28:08 2016 bougon_p
** Last update Thu Mar 10 13:48:21 2016 bougon_p
*/

#include "get_next_line.h"

char	*my_realloc(char *line)
{
  char  *new_line;
  int   size;
  int   i;

  i = 0;
  size = 0;
  while (line[size] != 0)
    size++;
  if ((new_line = malloc(sizeof(char) * (size + READ_SIZE) + 2)) == NULL)
    return (NULL);
  while (i < size)
    {
      new_line[i] = line[i];
      i++;
    }
  while (i < (size + READ_SIZE + 2))
    new_line[i++] = 0;
  free(line);
  return (new_line);
}

int	refill_line(t_file *file, char *buf, int i)
{
  if ( buf[i] == 0)
    {
      free(file->line);
      return (-1);
    }
  while (i < READ_SIZE)
    {
      if (buf[i] == '\n')
	return (i % READ_SIZE + 1);
      file->line[file->p++] = buf[i++];
    }
  if ((file->line = my_realloc(file->line)) == NULL)
    return (-1);
  return (0);
}

char	*fill_line(t_file *file, int fd, char *buf, int *i)
{
  while (file->nb_char != 0)
    {
      if ((file->nb_char = read(fd, buf, READ_SIZE)) == -1
	  || buf == NULL || (file->nb_char == 0 && file->count == 0)
	  || buf[0] == 0)
	{
	  free(file->line);
	  return (NULL);
	}
      buf[READ_SIZE] = 0;
      file->count++;
      *i = -1;
      while (++*i < file->nb_char)
	{
	  if (buf[*i] == '\n')
	    {
	      *i = (file->nb_char - *i == 1) ? 0 : *i + 1;
	      return (file->line);
	    }
	  file->line[file->p++] = buf[*i];
	}
      if ((file->line = my_realloc(file->line)) == NULL)
	return (NULL);
    }
  return (file->line);
}

int	init(t_file *file, char *buf, int cond)
{
  int	n;

  if (cond == 0)
    {
      file->nb_char = 1;
      file->count = 0;
      file->p = 0;
      if ((file->line = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
	return (1);
      n = -1;
      while (++n < READ_SIZE + 1)
	file->line[n] = 0;
    }
  else if (cond == 1)
    {
      n = -1;
      while (++n < READ_SIZE + 1)
	buf[n] = 0;
    }
  return (0);
}

char	*get_next_line(const int fd)
{
  static char	*buf;
  static int	i;
  t_file        file;

  if ((init(&file, buf, 0)) == 1)
    return (NULL);
  if (buf == NULL)
    {
      if ((buf = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
	return (NULL);
      init(&file, buf, 1);
    }
  else if (i <= READ_SIZE && i > 0)
    {
      if ((i = refill_line(&file, buf, i)) == -1)
	return (NULL);
      if (i > 0)
	return (file.line);
      if (i == 0)
	return (free(buf), buf = NULL, file.line);
    }
  return (fill_line(&file, fd, buf, &i));
}
