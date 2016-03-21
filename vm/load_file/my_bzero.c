/*
** my_bzero.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 13:44:11 2016 marc brout
** Last update Mon Mar 21 16:34:07 2016 marc brout
*/

void	my_bzero(void *var, int size, char val)
{
  int	i;
  char	*str;

  i = 0;
  str = (char *)var;
  while (i < size)
    str[i] = val;
}
