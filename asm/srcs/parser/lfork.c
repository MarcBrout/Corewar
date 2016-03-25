/*
** lfork.c for lfork in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:34:20 2016 bougon_p
** Last update Fri Mar 25 18:41:19 2016 bougon_p
*/

#include "asm.h"

int	w_lfork(t_info *info, int fd, t_instruc *instruc)
{
  char	istr;

  istr = 0x0f;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if (w_short(fd, info->arg_1, instruc) == 1)
    return (1);
  instruc->addr_wrt += 3;
  return (0);
}
