/*
** st.c for ST in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:27:09 2016 bougon_p
** Last update Tue Mar 15 21:23:50 2016 bougon_p
*/

#include "asm.h"

int	w_st(t_info *info, int fd)
{
  char	istr;

  istr = 0x03;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  return (0);
}
