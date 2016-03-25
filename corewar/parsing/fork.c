/*
** fork.c for fork in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:58:14 2016 benjamin duhieu
** Last update Fri Mar 25 12:00:59 2016 benjamin duhieu
*/

#include "vm.h"

int	frk(t_data *data, t_pc *i)
{
  int	val;

  val = (read_short_from_ram(data->ram, MM(i->reg[0] + 1)) % IDX_MOD);
  /* my_printf("FORK CHAMP = %s\n", i->champ->name); */
  /* my_printf("FORK Pos = %d\n", MM(i->reg[0])); */
  /* my_printf("FORK val = %d\n", val); */
  if (add_pc(i, MM(i->reg[0] + val), 800))
    return (1);
  /* my_printf("val = %d\n", i->next->reg[0]); */
  if (i->next->reg[0] < 0)
    i->next->reg[0] = MEM_SIZE - i->next->reg[0];
  i->cycle = 800;
  i->reg[0] = MM(i->reg[0] + 3);
  return (0);
}
