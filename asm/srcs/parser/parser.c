/*
** parser.c for PARSE in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar 10 15:08:25 2016 bougon_p
** Last update Thu Mar 17 20:26:42 2016 bougon_p
*/

#include "asm.h"

int	init_tabinstr(t_tabinstr *tabinstr)
{
  int   (**tab)(t_info *, int);

  if ((tab = malloc(sizeof(t_tabinstr) * NB_INSTRUCTIONS)) == NULL)
    return (1);
  tab[0] = &w_live;
  tab[1] = &w_ld;
  tab[2] = &w_st;
  tab[3] = &w_add;
  tab[4] = &w_sub;
  tab[5] = &w_and;
  tab[6] = &w_or;
  tab[7] = &w_xor;
  tab[8] = &w_zjmp;
  tab[9] = &w_ldi;
  tab[10] = &w_sti;
  tab[11] = &w_fork;
  tab[12] = &w_lld;
  tab[13] = &w_lldi;
  tab[14] = &w_lfork;
  tab[15] = &w_aff;
  tabinstr->tabinstr = tab;
  return (0);
}

char	**init_instr_end(char **tab)
{
  if ((tab[9] = my_strdup("ldi")) == NULL)
    return (NULL);
  if ((tab[10] = my_strdup("sti")) == NULL)
    return (NULL);
  if ((tab[11] = my_strdup("fork")) == NULL)
    return (NULL);
  if ((tab[12] = my_strdup("lld")) == NULL)
    return (NULL);
  if ((tab[13] = my_strdup("lldi")) == NULL)
    return (NULL);
  if ((tab[14] = my_strdup("lfork")) == NULL)
    return (NULL);
  if ((tab[15] = my_strdup("aff")) == NULL)
    return (NULL);
  return (tab);
}

char	**init_instr()
{
  char	**tab;

  if ((tab = malloc(sizeof(char *) * NB_INSTRUCTIONS + 1)) == NULL)
    return (NULL);
  tab[16] = NULL;
  if ((tab[0] = my_strdup("live")) == NULL)
    return (NULL);
  if ((tab[1] = my_strdup("ld")) == NULL)
    return (NULL);
  if ((tab[2] = my_strdup("st")) == NULL)
    return (NULL);
  if ((tab[3] = my_strdup("add")) == NULL)
    return (NULL);
  if ((tab[4] = my_strdup("sub")) == NULL)
    return (NULL);
  if ((tab[5] = my_strdup("and")) == NULL)
    return (NULL);
  if ((tab[6] = my_strdup("or")) == NULL)
    return (NULL);
  if ((tab[7] = my_strdup("xor")) == NULL)
    return (NULL);
  if ((tab[8] = my_strdup("zjmp")) == NULL)
    return (NULL);
  return (init_instr_end(tab));
}

int		parser(char *name, t_header *head, t_instruc *instruc)
{
  int		fd;
  t_tabinstr	tabinstr;
  char		**instr;

  if ((fd = create_file(name)) == 1)
    return (1);
  head->prog_size = 32;
  if (write_header(fd, head) == 1)
    return (1);
  init_tabinstr(&tabinstr);
  instr = init_instr();
  int i = -1;
  while (++i < NB_INSTRUCTIONS)
    printf("%s\n", instr[i]);
  if (write_code(fd, instruc, &tabinstr, instr) == 1)
    return (1);
  close(fd);
  return (0);
}
