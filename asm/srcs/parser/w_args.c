/*
** w_args.c for ARGS in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar 17 15:33:53 2016 bougon_p
** Last update Thu Mar 17 19:20:27 2016 bougon_p
*/

#include "asm.h"

int	w_reg(int fd, char *arg)
{
  char	reg;

  reg = my_getnbr(&arg[1]);
  if (write(fd, &reg, sizeof(reg)) == -1)
    return (1);
  return (0);
}

int	w_int(int fd, char *arg)
{
  int	arg_nb;

  arg_nb = my_getnbr(&arg[1]);
  arg_nb = convert_littleend_to_bigend_int(arg_nb);
  if (write(fd, &arg_nb, sizeof(arg_nb)) == -1)
    return (1);
  return (0);
}

int	w_short(int fd, char *arg)
{
  short	arg_nb;

  if (arg[0] == '%')
    arg_nb = my_getnbr(&arg[1]);
  else
    arg_nb = my_getnbr(arg);
  arg_nb = convert_littleend_to_bigend_short(arg_nb);
  if (write(fd, &arg_nb, sizeof(arg_nb)) == -1)
    return (1);
  return (0);
}
