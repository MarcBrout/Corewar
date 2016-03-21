/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/parser
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 15:41:48 2016
** Last update Mon Mar 21 18:48:33 2016 Marel la plus belle <3
*/

#include "asm.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	lexer(t_header *header, t_instruc *instruc, char *str)
{
  int	fd;
  char	*file;
  int	n;

  if ((fd = open(str, O_RDONLY)) == -1)
    return (-1);
  while (((file = get_next_line(fd)) != NULL && strlen(file) == 0)
	 || if_comment_text(file) == -1)
    free(file);
  if (check_name(header, file) == -1)
    return (-1);
  free(file);
  while (((file = get_next_line(fd)) != NULL && strlen(file) == 0)
	 || if_comment_text(file) == -1)
    free(file);
  if ((n = check_comment(header, file)) == -1)
    return (-1);
  if (check_instructions(instruc, fd) == -1)
    return (-1);
  if (check_if_label_exist(instruc) == -1)
    return (-1);
  free(file);
  return (0);
}
