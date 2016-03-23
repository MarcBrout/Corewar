/*
** lfork.c for lfork in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 23:01:38 2016 benjamin duhieu
** Last update Wed Mar 23 10:32:34 2016 benjamin duhieu
*/

#include "vm.h"

int	lfork(UNUSED t_data *data, t_pc *i)
{
  i->reg[0] += 2;
  return (0);
}
