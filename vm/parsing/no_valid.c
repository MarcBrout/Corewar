/*
** no_valid.c for no_valid in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Tue Mar 22 11:11:35 2016 benjamin duhieu
** Last update Tue Mar 22 11:49:11 2016 benjamin duhieu
*/

#include "vm.h"

void	put_no_valid(char *ramv, int i, int limit)
{
  int	a;

  a = -1;
  while (++a < limit)
    ramv[(i - 1) + a] = 0;
  i++;
}
