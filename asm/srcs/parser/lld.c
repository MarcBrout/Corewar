/*
** lld.c for lld in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:33:27 2016 bougon_p
** Last update Mon Mar 21 17:44:53 2016 bougon_p
*/

#include "asm.h"

int	lld_arg_1(int fd, t_info *info, char byte)
{
  char	check;

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

int	w_lld(t_info *info, int fd)
{
  char	istr;
  char	byte;

  istr = 0x0d;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if ((byte = w_coding_byte(fd, info)) == -1)
    return (1);
  if (lld_arg_1(fd, info, byte) == 1)
    return (1);
  if (w_reg(fd, info->arg_2) == 1)
    return (1);
  return (0);
}
