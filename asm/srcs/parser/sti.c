/*
** sti.c for sti in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:32:23 2016 bougon_p
** Last update Thu Mar 17 00:27:25 2016 bougon_p
*/

#include "asm.h"

int	w_sti(t_info *info, int fd)
{
  char	istr;
  short	arg;
  char	reg;

  istr = 0x0b;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if (w_coding_byte(fd, info) == -1)
    return (1);
  reg = my_getnbr(&info->arg_1[1]);
  if (write(fd, &reg, sizeof(reg)) == -1)
    return (1);
  arg = my_getnbr(&info->arg_2[1]);
  arg = convert_littleend_to_bigend_short(arg);
  if (write(fd, &arg, sizeof(arg)) == -1)
    return (1);
  arg = my_getnbr(&info->arg_3[1]);
  arg = convert_littleend_to_bigend_short(arg);
  if (write(fd, &arg, sizeof(arg)) == -1)
    return (1);
  return (0);
}
