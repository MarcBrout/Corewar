/*
** fork.c for fork in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:32:55 2016 bougon_p
** Last update Tue Mar 22 22:20:52 2016 bougon_p
*/

#include "asm.h"

int	w_fork(t_info *info, int fd, t_instruc *instruc)
{
  char	istr;

  istr = 0x0c;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  instruc->addr_wrt += 1;
  if (w_short(fd, info->arg_1) == 1)
    return (1);
  instruc->addr_wrt += 2;
  return (0);
}
