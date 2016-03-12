/*
** check_instructions.c for check_instructions in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/lexer
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 18:05:32 2016
** Last update Sat Mar 12 18:26:50 2016 
*/

#include "asm.h"

int	check_if_label(char *new)
{
  int	i;

  i = 0;
  while (new && new[i] != '\0' && new[i] != LABEL_CHAR)
    {
      if (check_char(new[i]) == -1)
	return (-1);
      i++;
    }
  if (new[i] == LABEL_CHAR)
    {
      printf("%s\n", new);
      return (0);
    }
  return (-1);
}

int			check_instruc_arg(t_instruc *instruc, char *file)
{
  char			*new;
  int			i;
  t_list_instruc	*inst;

  if ((inst = put_after(instruc)) == NULL)
    return (-1);
  if ((new = epure_file_instruc(file, 0)) == NULL)
    return (-1);
  i = 0;
  while (i < 16)
    {
      if (strncmp(new,
		  op_tab[i].mnemonique, strlen(op_tab[i].mnemonique)) == 0
	  && new[strlen(op_tab[i].mnemonique)] == ' ')
	{
	  inst->info->name = strcpy(inst->info->name, op_tab[i].mnemonique);
	  printf("%s\n", inst->info->name);
	  return (0);
	}
      i++;
    }
  if (check_if_label(new) == -1)
    return (-1);
  return (0);
}

int	put_instruc(t_instruc *instruc, int fd)
{
  char	*file;

  while ((file = get_next_line(fd)) != NULL && strlen(file) == 0);
  if (file != NULL)
    {
      if (check_instruc_arg(instruc, file) == -1)
	return (-1);
      put_instruc(instruc, fd);
    }
  return (0);
}

int	check_instructions(t_instruc *instruc, int fd)
{
  if (create_list(instruc) == -1)
    return (-1);
  put_instruc(instruc, fd);
  return (0);
}
