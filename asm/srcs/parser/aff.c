/*
** aff.c for aff in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:35:07 2016 bougon_p
** Last update Wed Mar 16 21:31:24 2016 bougon_p
*/

#include "asm.h"

int	w_aff(t_info *info, int fd)
{
  char	istr;

  istr = 0x10;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if (w_coding_byte(fd, info) == -1)
    return (1);
  return (0);
}
