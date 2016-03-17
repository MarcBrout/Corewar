/*
** sti.c for sti in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:32:23 2016 bougon_p
** Last update Thu Mar 17 16:19:53 2016 bougon_p
*/

#include "asm.h"

int	sti_arg_2(int fd, t_info *info, char byte)
{
  char	check;

  check = (byte >> 4);
  if (check == 0x07 || check == 0x06)
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

int	sti_arg_3(int fd, t_info *info, char byte)
{
  char	check;

  check = ((byte & 0x0C) >> 2);
  if (check == 0x02 || check == 0x03)
    {
      if (w_short(fd, info->arg_3) == 1)
	return (1);
    }
  else
    {
      if (w_reg(fd, info->arg_3) == 1)
	return (1);
    }
  return (0);
}

int	w_sti(t_info *info, int fd)
{
  char	istr;
  char	byte;

  istr = 0x0b;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if ((byte = w_coding_byte(fd, info)) == -1)
    return (1);
  if (w_reg(fd, info->arg_1) == 1)
    return (1);
  if (sti_arg_2(fd, info, byte) == 1)
    return (1);
  if (sti_arg_3(fd, info, byte) == 1)
    return (1);
  return (0);
}
