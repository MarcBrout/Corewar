/*
** lfork.c for lfork in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 23:01:38 2016 benjamin duhieu
** Last update Tue Mar 22 19:11:44 2016 benjamin duhieu
*/

#include "vm.h"

int	lfork(t_data *data, t_pc *i)
{
  i->reg[0] += 2;
}
