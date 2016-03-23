/*
** zjump.c for zjump in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:56:42 2016 benjamin duhieu
** Last update Tue Mar 22 19:03:28 2016 benjamin duhieu
*/

#include "vm.h"

int	zjump(t_data *data, t_pc *i)
{
  i->reg[0] += 2;
  return (0);
}
