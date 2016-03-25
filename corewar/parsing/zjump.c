/*
** zjump.c for zjump in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:56:42 2016 benjamin duhieu
** Last update Thu Mar 24 13:14:54 2016 marc brout
*/

#include "vm.h"
#include "my.h"

int		zjump(t_data *data, t_pc *i)
{
  short		jump_size;

  my_printf("ZJUMP carry = %d\n", i->carry);
  if (i->carry)
    {
      jump_size = read_short_from_ram(data->ram, MM(i->reg[0] + 1));
      my_printf("jump value = %d\n", jump_size);
      i->reg[0] = i->reg[0] + ((jump_size - 1) % IDX_MOD);
      if (i->reg[0] < 0)
	i->reg[0] = MEM_SIZE - i->reg[0];
    }
  i->cycle = 20;
  return (0);
}
