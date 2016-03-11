/*
** check_instructions.c for check_instructions in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/lexer
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 18:05:32 2016
** Last update Fri Mar 11 15:57:09 2016 
*/

#include "asm.h"

char	*epure_file_instruc(char *file, int i)
{
  int	j;
  char	*new;

  while (file && (file[i] == ' '
		  || file[i] == '\t' || file[i] == ',') && file[i])
    i++;
  j = 0;
  if ((new = malloc(sizeof(char) * (strlen(file) - i + 1))) == NULL)
    return (malloc_fail(), NULL);
  while (
}

int	check_instruc_arg(t_instruc *instruc, char *file)
{

}

int	put_instruc(t_instruc *instruc, int fd)
{
  char	*file;

  while ((file = get_next_line(fd)) != NULL && strlen(file) == 0);
  if (file != NULL)
    {
      check_instruc_arg(instruc, file);
      put_instruc(instruc, fd);
    }
}

int	check_instructions(t_instruc *instruc, int fd)
{
  if (create_list(instruct) == -1)
    return (-1);
  check_put_instruc(instruc, fd);
  return (0);
}
