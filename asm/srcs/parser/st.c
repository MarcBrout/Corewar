/*
** st.c for ST in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:27:09 2016 bougon_p
** Last update Fri Mar 18 18:08:29 2016 bougon_p
*/

#include "asm.h"

int	st_arg_2(int fd, t_info *info, char byte)
{
  char  check;

  check = (byte >> 4);
  if (check == 0x07)
    {
      if (w_short(fd, info->arg_2) == 1)
        return (1);
    }
  else
    {
      if (w_reg(fd, info->arg_2) == 1)
        return (1);
    }
  return (0);
}

int	w_st(t_info *info, int fd)
{
  char	byte;
  char	istr;

  istr = 0x03;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if ((byte = w_coding_byte(fd, info)) == -1)
    return (1);
  if (w_reg(fd, info->arg_1) == 1)
    return (1);
  if (st_arg_2(fd, info, byte) == 1)
    return (1);
  return (0);
}
