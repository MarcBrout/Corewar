/*
** my_power_rec.c for lib
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 14 18:50:35 2016 marc brout
** Last update Mon Mar 14 18:54:45 2016 marc brout
*/

int	my_power_rec(int nb, int i)
{
  if (i == 0)
    return (-1);
  if (i == 1)
    return (nb);
  i = i - 1;
  nb *= my_power_rec(nb, i);
  return (nb);
}
