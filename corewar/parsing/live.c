/*
** live-suv.c for live-sub in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 21:40:56 2016 benjamin duhieu
** Last update Wed Mar 23 10:32:52 2016 benjamin duhieu
*/

#include "vm.h"

int	live(UNUSED t_data *data, t_pc *i)
{
  i->reg[0] += 4;
  return (0);
}
