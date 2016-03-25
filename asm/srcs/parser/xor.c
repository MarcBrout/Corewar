/*
** xor.c for xor in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:59:22 2016 bougon_p
** Last update Wed Mar 23 22:42:32 2016 bougon_p
*/

#include "asm.h"

int	xor_arg_1(int fd, t_info *info, char byte, t_instruc *instruc)
{
  char	check;

  check = ((byte & 0xC0) >> 6);
  if (check == 0x02)
    {
      if (check_int_lab(info, instruc, info->arg_1) == true)
	return (0);
      if (w_int(fd, info->arg_1) == 1)
        return (1);
      instruc->addr_wrt += 4;
    }
  else if (check == 0x03)
    {
      if (w_short(fd, info->arg_1) == 1)
        return (1);
      instruc->addr_wrt += 2;
    }
  else if (check == 0x01)
    {
      if (w_reg(fd, info->arg_1) == 1)
        return (1);
      instruc->addr_wrt += 1;
    }
  return (0);
}

int	xor_arg_2(int fd, t_info *info, char byte, t_instruc *instruc)
{
  char	check;

  check = ((byte & 0x30) >> 4);
  if (check == 0x02)
    {
      if (check_int_lab(info, instruc, info->arg_2) == true)
	return (0);
      if (w_int(fd, info->arg_2) == 1)
        return (1);
      instruc->addr_wrt += 4;
    }
  else if (check == 0x03)
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

int	w_xor(t_info *info, int fd, t_instruc *instruc)
{
  char	istr;
  char	byte;

  istr = 0x08;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if ((byte = w_coding_byte(fd, info)) == -1)
    return (1);
  instruc->addr_wrt += 2;
  if (xor_arg_1(fd, info, byte, instruc) == 1)
    return (1);
  if (xor_arg_2(fd, info, byte, instruc) == 1)
    return (1);
  if (w_reg(fd, info->arg_3) == 1)
    return (1);
  instruc->addr_wrt += 1;
  return (0);
}
