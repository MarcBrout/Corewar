/*
** dasm.h for corware in /home/brout_m/RENDU/CPE/CPE_2015_corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 14 10:51:24 2016 marc brout
** Last update Tue Mar 15 18:29:57 2016 marc brout
*/

#ifndef DASM_H_
# define DASM_H_

# define USAGE "USAGE : ./dasm file.cor\n"
# define UNUSED __attribute__((__unused__))

typedef int			(*t_instruction)(int, int);

typedef struct		s_dasm
{
  t_instruction		instruc[16];
  char			cb;
}			t_dasm;

void			set_line_null(char *str, int size);
char			*setnbr(int nbr);

#endif /* !DASH_H_ */
