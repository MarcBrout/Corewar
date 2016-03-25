/*
** labs.c for LABELS in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 22 20:39:57 2016 bougon_p
** Last update Fri Mar 25 00:46:56 2016 bougon_p
*/

#include "asm.h"

void		refind_the_lab(t_instruc *instruc, t_cdlist *to_find)
{
  t_cdlist	*tmp_real;

  tmp_real = instruc->real_lab.root->next;
  while (tmp_real != instruc->real_lab.root)
    {
      /* printf("\nADDRESSAGE ==>%d\n", */
	     /* HEADER_SIZE + to_find->data->addr); */
      /* printf("REALNAME -> %s || CALL_TO NAME -> %s \n\n", */
	     /* tmp_real->data->name, to_find->data->name); */
      if (my_strcmp(to_find->data->name, tmp_real->data->name) == 0)
	{
	  lseek(instruc->fd, HEADER_SIZE +
		to_find->data->addr, SEEK_SET);
	  w_label(instruc->fd, to_find, tmp_real);
	  return ;
	}
      tmp_real = tmp_real->next;
    }
}

int		write_labels(t_instruc *instruc)
{
  t_cdlist	*tmp_call;

  tmp_call = instruc->call_to_lab.root->next;
  while (tmp_call != instruc->call_to_lab.root)
    {
      refind_the_lab(instruc, tmp_call);
      tmp_call = tmp_call->next;
    }
  return (0);
}

bool		check_short_lab(UNUSED t_info *info, t_instruc *instruc, char *arg)
{
  short		pad;
  t_lablist	*lab;

  if (arg[1] == ':')
    {
      if ((lab = malloc(sizeof(t_lablist))) == NULL)
	return (false);
      lab->addr = instruc->addr_vir + instruc->addr_wrt;
      lab->name = my_strdup(&arg[2]);
      lab->nb_bytes = 2;
      if (my_strcmp(info->name, "zjmp") == 0 ||
	  my_strcmp(info->name, "fork") == 0 ||
	  my_strcmp(info->name, "ld") == 0)
	lab->zjmp = true;
      else
	lab->zjmp = false;
      add_last_labcdl(instruc->call_to_lab.root, lab);
      instruc->addr_vir += 2;
      pad = 0;
      write(instruc->fd, &pad, sizeof(pad));
      return (true);
    }
  return (false);
}

bool	check_int_lab(UNUSED t_info *info, t_instruc *instruc, char *arg)
{
  int		pad;
  t_lablist	*lab;

  if (arg[1] == ':')
    {
      if ((lab = malloc(sizeof(t_lablist))) == NULL)
	return (false);
      lab->addr = instruc->addr_vir + instruc->addr_wrt;
      lab->name = my_strdup(&arg[2]);
      lab->nb_bytes = 4;
      if (my_strcmp(info->name, "zjmp") == 0 ||
	  my_strcmp(info->name, "fork") == 0 ||
	  my_strcmp(info->name, "ld") == 0)
	lab->zjmp = true;
      else
	lab->zjmp = false;
      add_last_labcdl(instruc->call_to_lab.root, lab);
      instruc->addr_vir += 4;
      pad = 0;
      write(instruc->fd, &pad, sizeof(pad));
      return (true);
    }
  return (false);
}
