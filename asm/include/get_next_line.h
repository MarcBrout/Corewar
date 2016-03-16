/*
** get_next_line.h for get_line in /home/bougon_p/rendu/CPE_2016_getnextline
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Jan  4 19:36:13 2016 bougon_p
** Last update Wed Mar 16 10:37:13 2016 
*/

#ifndef GET_NEXT_LINE_H_

# define  GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (4096)
# endif /* !READ_SIZE */

typedef struct	s_file
{
  int		count;
  int		p;
  int		nb_char;
  char		*line;
}		t_file;

#endif /* !GET_NEXT_LINE_H_ */
