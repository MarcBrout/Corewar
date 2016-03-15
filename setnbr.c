/*
** setnbr.c for tools in /home/bougon_p/rendu/CPE_2015_corewar
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 14 22:15:24 2016 bougon_p
** Last update Mon Mar 14 22:49:42 2016 bougon_p
*/

#include <stdlib.h>

char	*cleanstr(char *nbr)
{
  char	*clean;
  int	p;
  int	i;

  if ((clean = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  set_line_null(clean, 10);
  p = 0;
  while (nbr[p++] == '0' && p < 10);
  if (p == 10)
    {
      clean[0] = '0';
      clean[1] = 0;
      free(nbr);
      return (clean);
    }
  i = 0;
  p--;
  while (nbr[p] != 0)
    clean[i++] = nbr[p++];
  free(nbr);
  return (clean);
}

char	*setnbr(int nbr)
{
  char	*numb;
  int	i;
  int	p;

  p = 8;
  if ((numb = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  set_line_null(numb, 10);
  i = 0;
  while (p >= 0)
    numb[p--] = ((nbr / (int)(pow(10, i++)) % 10) + '0');
  return (cleanstr(numb));
}

int	main()
{
  char	*s;
  int	nb = 123123;

  s = setnbr(nb);
  printf("%s\n", s);
  free(s);
}
