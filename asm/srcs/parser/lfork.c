/*
** lfork.c for lfork in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:34:20 2016 bougon_p
** Last update Wed Mar 16 22:20:34 2016 bougon_p
*/

#include "asm.h"

int	w_lfork(UNUSED t_info *info, int fd)
{
  char	istr;

  istr = 0x0f;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  return (0);
}
