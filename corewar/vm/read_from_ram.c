/*
** read_from_ram.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Mar 23 08:36:28 2016 marc brout
** Last update Wed Mar 23 09:52:19 2016 marc brout
*/

#include <stdio.h>
#include "vm.h"
#include "my.h"

int		read_int_from_ram(char *ram, int pos)
{
  t_core_int	nb;

  if (g_endian)
    {
      nb.bytes[3] = ram[pos];
      nb.bytes[2] = ram[pos + 1];
      nb.bytes[1] = ram[pos + 2];
      nb.bytes[0] = ram[pos + 3];
    }
  else
    {
      nb.bytes[0] = ram[pos];
      nb.bytes[1] = ram[pos + 1];
      nb.bytes[2] = ram[pos + 2];
      nb.bytes[3] = ram[pos + 3];
    }
  return (nb.value);
}

short		read_short_from_ram(char* ram, int pos)
{
  t_core_short	nb;

  if (g_endian)
    {
      nb.bytes[1] = ram[pos];
      nb.bytes[0] = ram[pos + 1];
    }
  else
    {
      nb.bytes[0] = ram[pos];
      nb.bytes[1] = ram[pos + 1];
    }
  return (nb.value);
}
