/*
** or.c for or in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:30:32 2016 bougon_p
** Last update Tue Mar 15 21:42:43 2016 bougon_p
*/

#include "asm.h"

int	w_or(t_info *info, int fd)
{
  char	istr;

  istr = 0x07;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  return (0);
}
