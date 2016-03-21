/*
** instruc_three_args.c for instruc_three_args in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Wed Mar 16 11:24:18 2016
** Last update Mon Mar 21 19:08:23 2016 Marel la plus belle <3
*/

#include "asm.h"

int	reg_reg_reg(UNUSED t_instruc *instruc, t_list_instruc *elem,
		    char *file)
{
  char	*new;
  char	*new2;

  if (check_registre_arg(elem, file, 1) == -1
      || (new = epure_file_instruc(file,
				   my_strlen(elem->info->arg_1))) == NULL
      || check_registre_arg(elem, new, 2) == -1
      || (new2 = epure_file_instruc(new,
				   my_strlen(elem->info->arg_2))) == NULL
      || check_registre_arg(elem, new2, 3) == -1)
    return (-1);
  if (check_end_instruc(new2, my_strlen(elem->info->arg_3)) == -1)
    return (-1);
  free(new);
  free(new2);
  return (0);
}

int	regdirin_regdirin_reg(t_instruc *instruc, t_list_instruc *elem,
			      char *file)
{
  char	*new;
  char	*new2;

  if ((check_registre_arg(elem, file, 1) == -1
       && check_direct_arg(instruc, elem, file, 1) == -1
       && check_indirect_arg(instruc, elem, file, 1) == -1)
      || (new = epure_file_instruc(file,
				   my_strlen(elem->info->arg_1))) == NULL
      || (check_registre_arg(elem, new, 2) == -1
	  && check_direct_arg(instruc, elem, new, 2) == -1
	  && check_indirect_arg(instruc, elem, new, 2) == -1)
      || (new2 = epure_file_instruc(new,
				    my_strlen(elem->info->arg_2))) == NULL
      || check_registre_arg(elem, new2, 3) == -1)
    return (-1);
  if (check_end_instruc(new2, my_strlen(elem->info->arg_3)) == -1)
    return (-1);
  free(new);
  free(new2);
  return (0);
}

int	regdirin_regdir_reg(t_instruc *instruc, t_list_instruc *elem,
			    char *file)
{
  char	*new;
  char	*new2;

  if ((check_registre_arg(elem, file, 1) == -1
       && check_direct_arg(instruc, elem, file, 1) == -1
       && check_indirect_arg(instruc, elem, file, 1) == -1)
      || (new = epure_file_instruc(file,
				   my_strlen(elem->info->arg_1))) == NULL
      || (check_registre_arg(elem, new, 2) == -1
	  && check_direct_arg(instruc, elem, new, 2) == -1)
      || (new2 = epure_file_instruc(new,
				    my_strlen(elem->info->arg_2))) == NULL
      || check_registre_arg(elem, new2, 3) == -1)
    return (-1);
  if (check_end_instruc(new2, my_strlen(elem->info->arg_3)) == -1)
    return (-1);
  free(new);
  free(new2);
  return (0);
}

int	reg_regdirin_regdir(t_instruc *instruc, t_list_instruc *elem,
			    char *file)
{
  char	*new;
  char	*new2;

  if (check_registre_arg(elem, file, 1) == -1
      || (new = epure_file_instruc(file,
				   my_strlen(elem->info->arg_1))) == NULL
      || (check_registre_arg(elem, new, 2) == -1
	  && check_direct_arg(instruc, elem, new, 2) == -1
	  && check_indirect_arg(instruc, elem, new, 2) == -1)
      || (new2 = epure_file_instruc(new,
				    my_strlen(elem->info->arg_2))) == NULL
      || (check_registre_arg(elem, new2, 3) == -1
	  && check_direct_arg(instruc, elem, new2, 3) == -1))
    return (-1);
  if (check_end_instruc(new2, my_strlen(elem->info->arg_3)) == -1)
    return (-1);
  free(new);
  free(new2);
  return (0);
}

t_three_args	*init_tab_three_args()
{
  t_three_args	*tab;

  if ((tab = malloc(sizeof(t_three_args) * MAX_THREE_ARGS)) == NULL)
    return (malloc_fail(), NULL);
  tab[ADD].ins = 3;
  tab[ADD].ft_three = &reg_reg_reg;
  tab[SUB].ins = 4;
  tab[SUB].ft_three = &reg_reg_reg;
  tab[AND].ins = 5;
  tab[AND].ft_three = &regdirin_regdirin_reg;
  tab[OR].ins = 6;
  tab[OR].ft_three = &regdirin_regdirin_reg;
  tab[XOR].ins = 7;
  tab[XOR].ft_three = &regdirin_regdirin_reg;
  tab[LDI].ins = 9;
  tab[LDI].ft_three = &regdirin_regdir_reg;
  tab[STI].ins = 10;
  tab[STI].ft_three = &reg_regdirin_regdir;
  tab[LLDI].ins = 13;
  tab[LLDI].ft_three = &regdirin_regdir_reg;
  return (tab);
}
