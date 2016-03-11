/*
** header.h for header in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 15:32:59 2016
** Last update Fri Mar 11 13:54:40 2016 bougon_p
*/

#ifndef HEADER_H_
# define HEADER_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

#include "get_next_line.h"

# define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct		s_header
{
  int			magic;
  char			prog_name[129];
  int			prog_size;
  char			comment[2049];
}			t_header;

typedef struct		s_instruc
{
  char			**ins;
}			t_instruc;

char			*get_next_line(int);
int			check_name(t_header *, char *);

#endif /* !HEADER_H_ */
