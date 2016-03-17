/*
** ld.c for LD in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:26:16 2016 bougon_p
** Last update Wed Mar 16 21:31:58 2016 bougon_p
*/

#include "asm.h"

int	w_ld(t_info *info, int fd)
{
  char	istr;

  istr = 0x02;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  if (w_coding_byte(fd, info) == -1)
    return (1);
  return (0);
}
