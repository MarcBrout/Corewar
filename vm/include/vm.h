/*
** vm.h for vm
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 10:36:14 2016 marc brout
** Last update Tue Mar 22 00:17:20 2016 marc brout
*/

#ifndef VM_H_
# define VM_H_

# include "op.h"

/*
** ERROR OUTPUTS
*/

# define OVERLAP "Overlap detected.\n"
# define MALLOC_ERROR "Can't perform malloc\n"
# define NOCOREWAR " is not a corewar executable\n"
# define CORRUPT " is corrupted\n"

extern char		g_endian;

typedef enum		e_vm_index
  {
    ERROR_NULL		= 0,
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
  int			pc;
  struct s_pc		*next;
}			t_pc;

typedef struct		s_champion
{
  const char		*path;
  char			valid;
  char			alive;
  int			order;
  int			fd;
  unsigned int		size;
  char			name[PROG_NAME_LENGTH + 1];
  t_pc			*pc;
}			t_champion;

typedef struct		s_data
{
  int			dump;
  int			i;
  t_champion		*champ[4];
  char			*ram;
  char			*ramv;
}			t_data;

typedef struct		s_pars
{
  char			*arg;
  int			(*chk_arg)(char **, int *, t_data *);
  struct s_pars		*next;
}			t_pars;


/*
** load_file.c
*/

char			endianness();
int			swap_integer(int nb);
int			check_header(int fd, t_header *head);
void			copy(char *src, char *dst);
int			init_champs(t_data *data);
int			load_champion(t_champion *champion,
				      const char *champion_file);

/*
** vm.c
*/

int			my_put_file_str(const char *file,
					const char *str,
					int err);
int			my_put_file_noaccess(const char *file,
					     int err);
int			my_put_error(const char *str,
				     int err);
int			my_put_usage(char **av,
				     int err);

/*
** misc.c
*/

void			my_putnbr_tofd(int nb, int fd);
int			my_strlencst(const char *str);
int			my_mystrcmpcst(const char *str1,
				       const char *str2);
int			my_revstrncmpcst(const char *str1,
					 const char *str2);
char			*my_strcatcst(const char *str1,
				      const char *str2);
char			*get_name(const char *str1,
				  const char *str2);
/*
** set_vm_memory.c
*/

int			init_ram(t_data *data);
int			copy_champion_to_ram(t_champion *champion,
					     char *ram);
int			size_champs(t_champion *champ[4],
				    int first,
				    int *nb);
int			place_all_champions(t_data *data);

#endif /* !VM_H_ */
