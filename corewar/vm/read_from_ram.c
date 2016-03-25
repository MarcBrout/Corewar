/*
** read_from_ram.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Mar 23 08:36:28 2016 marc brout
** Last update Thu Mar 24 15:05:00 2016 marc brout
*/

#include <stdio.h>
#include "vm.h"
#include "my.h"

int		read_int_from_ram(char *ram, int pos)
{
  t_core_int	nb;

  if (g_endian)
    {
      nb.bytes[3] = ram[pos % MEM_SIZE];
      nb.bytes[2] = ram[(pos + 1) % MEM_SIZE];
      nb.bytes[1] = ram[(pos + 2) % MEM_SIZE];
      nb.bytes[0] = ram[(pos + 3) % MEM_SIZE];
    }
  else
    {
      nb.bytes[0] = ram[pos % MEM_SIZE];
      nb.bytes[1] = ram[(pos + 1) % MEM_SIZE];
      nb.bytes[2] = ram[(pos + 2) % MEM_SIZE];
      nb.bytes[3] = ram[(pos + 3) % MEM_SIZE];
    }
  return (nb.value);
}

short		read_short_from_ram(char* ram, int pos)
{
  t_core_short	nb;

  if (g_endian)
    {
      nb.bytes[1] = ram[pos % MEM_SIZE];
      nb.bytes[0] = ram[(pos + 1) % MEM_SIZE];
    }
  else
    {
      nb.bytes[0] = ram[pos % MEM_SIZE];
      nb.bytes[1] = ram[(pos + 1) % MEM_SIZE];
    }
  return (nb.value);
}

void		write_int_to_ram(char *ram, int val, int pos)
{
  t_core_int	nb;

  nb.value = val;
  if (g_endian)
    {
      ram[pos % MEM_SIZE] = nb.bytes[3];
      ram[(pos + 1) % MEM_SIZE] = nb.bytes[2];
      ram[(pos + 2) % MEM_SIZE] = nb.bytes[1];
      ram[(pos + 3) % MEM_SIZE] = nb.bytes[0];
    }
  else
    {
      ram[pos % MEM_SIZE] = nb.bytes[0];
      ram[(pos + 1) % MEM_SIZE] = nb.bytes[1];
      ram[(pos + 2) % MEM_SIZE] = nb.bytes[2];
      ram[(pos + 3) % MEM_SIZE] = nb.bytes[3];
    }
}

void		write_short_to_ram(char *ram, short val, int pos)
{
  t_core_short	nb;

  nb.value = val;
  if (g_endian)
    {
      ram[(pos + 2) % MEM_SIZE] = nb.bytes[1];
      ram[(pos + 3) % MEM_SIZE] = nb.bytes[0];
    }
  else
    {
      ram[pos % MEM_SIZE] = nb.bytes[0];
      ram[(pos + 1) % MEM_SIZE] = nb.bytes[1];
    }
}
