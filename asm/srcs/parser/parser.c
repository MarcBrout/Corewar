/*
** parser.c for PARSE in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar 10 15:08:25 2016 bougon_p
** Last update Tue Mar 22 11:51:40 2016 bougon_p
*/

#include "asm.h"

int	init_tabinstr(t_tabinstr *tabinstr)
{
  if ((tabinstr->tabinstr = malloc
       (sizeof(t_tabinstr) * NB_INSTRUCTIONS)) == NULL)
    return (1);
  tabinstr->tabinstr[0] = &w_live;
  tabinstr->tabinstr[1] = &w_ld;
  tabinstr->tabinstr[2] = &w_st;
  tabinstr->tabinstr[3] = &w_add;
  tabinstr->tabinstr[4] = &w_sub;
  tabinstr->tabinstr[5] = &w_and;
  tabinstr->tabinstr[6] = &w_or;
  tabinstr->tabinstr[7] = &w_xor;
  tabinstr->tabinstr[8] = &w_zjmp;
  tabinstr->tabinstr[9] = &w_ldi;
  tabinstr->tabinstr[10] = &w_sti;
  tabinstr->tabinstr[11] = &w_fork;
  tabinstr->tabinstr[12] = &w_lld;
  tabinstr->tabinstr[13] = &w_lldi;
  tabinstr->tabinstr[14] = &w_lfork;
  tabinstr->tabinstr[15] = &w_aff;
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
  tab[16] = NULL;
  return (tab);
}

char	**init_instr()
{
  char	**tab;

  if ((tab = malloc(sizeof(char *) * (NB_INSTRUCTIONS + 1))) == NULL)
    return (NULL);
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
  init_instr_end(tab);
  return (tab);
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
  if (write_code(fd, instruc, &tabinstr, instr) == 1)
    return (1);
  close(fd);
  free_tab(instr);
  free(tabinstr.tabinstr);
  return (0);
}
