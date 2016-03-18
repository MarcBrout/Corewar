/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/parser
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 15:41:48 2016
** Last update Fri Mar 18 18:19:35 2016 
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
	 || if_comment_text(file) == -1);
  if (check_name(header, file) == -1)
    return (-1);
  while (((file = get_next_line(fd)) != NULL && strlen(file) == 0)
	 || if_comment_text(file) == -1);
  if ((n = check_comment(header, file)) == -1)
    return (-1);
  if (check_instructions(instruc, fd) == -1)
    return (-1);
  if (check_if_label_exist(instruc) == -1)
    {
      printf("d\n");
      return (-1);
    }
  return (0);
}
