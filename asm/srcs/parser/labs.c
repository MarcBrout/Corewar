/*
** labs.c for LABELS in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 22 20:39:57 2016 bougon_p
** Last update Tue Mar 22 20:45:23 2016 bougon_p
*/

#include "asm.h"

bool	check_short_lab(t_info *info, t_instruc *instruc)
{
  if (info->arg_1[1] == ':')
    {
      /*stock position
	stock le nom*/
      instruc->addr_vir += 2;
      return (true);
    }
  return (false);
}

bool	check_int_lab(t_info *info, t_instruc *instruc)
{
  if (info->arg_1[1] == ':')
    {
      /*stock position
	stock le nom*/
      instruc->addr_vir += 4;
      return (true);
    }
  return (false);
}
