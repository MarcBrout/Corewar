/*
** st.c for ST in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:27:09 2016 bougon_p
** Last update Tue Mar 22 21:26:07 2016 bougon_p
*/

#include "asm.h"

int	st_arg_2(int fd, t_info *info, char byte, t_instruc *instruc)
{
  char  check;

  check = ((byte & 0x30) >> 4);
  if (check == 0x03)
    {
      if (w_short(fd, info->arg_2) == 1)
        return (1);
      instruc->addr_wrt += 2;
    }
  else
    {
      if (w_reg(fd, info->arg_2) == 1)
        return (1);
      instruc->addr_wrt += 1;
    }
  return (0);
}

int	w_st(t_info *info, int fd, t_instruc *instruc)
{
  char	byte;
  char	istr;

  istr = 0x03;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if ((byte = w_coding_byte(fd, info)) == -1)
    return (1);
  instruc->addr_wrt += 2;
  if (w_reg(fd, info->arg_1) == 1)
    return (1);
  instruc->addr_wrt += 1;
  if (st_arg_2(fd, info, byte, instruc) == 1)
    return (1);
  return (0);
}
