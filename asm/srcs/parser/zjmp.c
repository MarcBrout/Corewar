/*
** zjmp.c for zjmp in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:31:15 2016 bougon_p
** Last update Tue Mar 22 21:48:19 2016 bougon_p
*/

#include "asm.h"

int	w_zjmp(t_info *info, int fd, t_instruc *instruc)
{
  char	istr;

  istr = 0x09;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if (w_short(fd, info->arg_1) == 1)
    return (1);
  instruc->addr_wrt += 3;
  return (0);
}
