/*
** my_strncpy.c for my_strncpy in /home/marel_m/rendu/Piscine_C_J06/ex_03
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Oct  5 11:17:08 2015 maud marel
** Last update Wed Mar 16 10:33:54 2016 
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src && i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
