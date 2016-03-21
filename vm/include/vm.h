/*
** vm.h for vm
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 10:36:14 2016 marc brout
** Last update Mon Mar 21 14:42:28 2016 benjamin duhieu
*/

#ifndef VM_H_
# define VM_H_

typedef enum		e_vm_index
  {
    FIRST		= 0,
    LIVE		= 1,
    LD			= 2,
    ST			= 3,
    ADD			= 4,
    SUB			= 5,
    AND			= 6,
    OR			= 7,
    XOR			= 8,
    ZJUMP		= 9,
    LDI			= 10,
    STI			= 11,
    FORK		= 12,
    LLD			= 13,
    LLDI		= 14,
    LFORK		= 15,
    AFF			= 16
  }			t_vm_index;

typedef	struct		s_pc
{
  unsigned int		pc;
  struct s_pc		*next;
}			t_pc;

typedef struct		s_champion
{
  char			valid;
  char			alive;
  int			order;
  char			name[PROG_NAME_LENGTH + 1];
  t_pc			*pc;
}			t_champion;

typedef struct		s_data
{
  int			dump;
  int			place_champ;
  t_champion		champ[4];
}			t_data;

typedef struct		s_pars
{
  char			*arg;
  int			(*chk_arg)(char **, int *, t_data *);
  struct s_pars		*next;
}			t_pars;

#endif /* !VM_H_ */
