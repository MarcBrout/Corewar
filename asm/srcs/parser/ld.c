/*
** ld.c for LD in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:26:16 2016 bougon_p
** Last update Thu Mar 17 19:21:23 2016 bougon_p
*/

#include "asm.h"

int     ld_arg_1(int fd, t_info *info, char byte)
{
  char  check;

  check = ((byte & 0xC0) >> 6);
  if (check == 0x02)
    {
      if (w_int(fd, info->arg_1) == 1)
        return (1);
    }
  else if (check == 0x03)
    {
      if (w_short(fd, info->arg_1) == 1)
        return (1);
    }
  return (0);
}

int	w_ld(t_info *info, int fd)
{
  char	istr;
  char	byte;

  istr = 0x02;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if ((byte = w_coding_byte(fd, info)) == -1)
    return (1);
  if (ld_arg_1(fd, info, byte) == 1)
    return (1);
  if (w_reg(fd, info->arg_2) == 1)
    return (1);
  return (0);
}
