/*
** sub.c for sub in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:28:06 2016 bougon_p
** Last update Thu Mar 17 19:48:52 2016 bougon_p
*/

#include "asm.h"

int	w_sub(t_info *info, int fd)
{
  char	istr;

  istr = 0x05;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if (w_coding_byte(fd, info) == -1)
    return (1);
  if ((w_reg(fd, info->arg_1)) == 1)
    return (1);
  if ((w_reg(fd, info->arg_2)) == 1)
    return (1);
  if ((w_reg(fd, info->arg_3)) == 1)
    return (1);
  return (0);
}
