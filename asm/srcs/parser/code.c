/*
** code.c for CODE in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 18:23:04 2016 bougon_p
** Last update Tue Mar 15 21:10:15 2016 bougon_p
*/

#include "asm.h"

int	check_instruct(char *name, char **tabname)
{
  int	i;

  i = 0;
  while (my_strcmp(name, tabname[i]) != 0)
    {
      i++;
      if (i > NB_INSTRUCTIONS)
	return (-1);
    }
  return (i);
}

int	write_line(t_info *line, int fd,
		   t_tabinstr *tabinstr, char **instr)
{
  int	index;


  if ((index = check_instruct(line->name, instr)) == -1)
    return (1);
  if (tabinstr->tabinstr[index](line, fd) == 1)
    return (1);
  return (0);
}

int		write_code(int fd, t_instruc *instruc,
			   t_tabinstr *tabinstr, char **instr)
{
  t_list_instruc	*act_instr;

  act_instr = instruc->root->next;
  while (act_instr != instruc->root)
    {
      if (write_line(act_instr->info, fd, tabinstr, instr) == 1)
	return (1);
      act_instr = act_instr->next;
    }
  return (0);
}
