/*
** fork.c for fork in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:32:55 2016 bougon_p
** Last update Wed Mar 16 22:06:54 2016 bougon_p
*/

#include "asm.h"

int	w_fork(UNUSED t_info *info, int fd)
{
  char	istr;

  istr = 0x0c;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  return (0);
}
