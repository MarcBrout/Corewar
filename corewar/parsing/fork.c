/*
** fork.c for fork in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:58:14 2016 benjamin duhieu
** Last update Wed Mar 23 10:32:24 2016 benjamin duhieu
*/

#include "vm.h"

int	frk(UNUSED t_data *data, t_pc *i)
{
  i->reg[0] += 2;
  return (0);
}
