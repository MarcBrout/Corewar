/*
** ldi.c for ldi in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:31:48 2016 bougon_p
** Last update Tue Mar 15 21:45:17 2016 bougon_p
*/

#include "asm.h"

int	w_ldi(t_info *info, int fd)
{
  char	istr;

  istr = 0x0a;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  return (0);
}