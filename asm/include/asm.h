/*
** header.h for header in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 15:32:59 2016
** Last update Mon Mar 14 19:06:54 2016 bougon_p
*/

#ifndef HEADER_H_
# define HEADER_H_

# include "get_next_line.h"
# include "op.h"
# include "my.h"

# define COREWAR_EXEC_MAGIC 0xea83f3

enum			check_one_arg
  {
    LIVE,
    LFORK,
    FORK,
    ZJMP,
    AFF,
    MAX_ONE_ARG
  };

typedef struct		s_check_one_arg
{
  char			*arg;
  void			(*ft_one)();
}			t_check_one_arg;

enum			check_two_args
  {
    LD,
    LLD,
    ST,
    MAX_TWO_ARGS
  };

typedef struct		s_check_two_arg
{
  char			*arg;
  void			(*ft_two)();
}			t_check_two_arg;

enum			check_three_args
  {
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    LDI,
    LLDI,
    STI,
    MAX_THREE_ARGS
  };

typedef struct		s_check_three_arg
{
  char			*arg;
  void			(*ft_three)();
}			t_check_three_arg;

typedef struct		s_header
{
  int			magic;
  char			prog_name[129];
  int			prog_size;
  char			comment[2049];
}			t_header;

typedef struct		s_info
{
  char			*name;
  char			*arg_1;
  char			*arg_2;
  char			*arg_3;
  char			*label;
}			t_info;

typedef struct		s_list_instruc
{
  t_info		*info;
  struct s_list_instruc	*next;
  struct s_list_instruc	*prev;
}			t_list_instruc;

typedef struct		s_instruc
{
  int			lenght;
  t_list_instruc	*root;
}			t_instruc;

/*
**Fonctions Lexer
*/

int			lexer(t_header *, t_instruc *, char *);
char			*get_next_line(int);
int			check_name(t_header *, char *);
char			*epure_file_name_com(char *, int);
int			check_char(char);
int			create_list(t_instruc *);
t_list_instruc		*add_list_after(t_instruc *);
char			*epure_file_instruc(char *, int);
void			malloc_fail();
int			check_comment(t_header *, char *);
int			check_instructions(t_instruc *, int);
int			check_which_instruc(t_instruc *, t_list_instruc *,
					    char *);
int			check_stock_good_args(t_list_instruc *, char *, int);
void			print_list(t_instruc *);
int			check_direct_arg(t_list_instruc *, char *, int);
int			check_registre_arg(t_list_instruc *, char *, int);
int			check_indirect_arg(t_list_instruc *, char *, int);
int			stock_args(t_list_instruc *, char *, int);

/*
** Parser functions
*/

int	parser(char *, t_header *);
void	set_line_null(char *, int);
int	convert_bigend_to_littleend_int(int);
int	create_file(char *);

/*
** TOOLS
*/

char	*my_strncpy(char *, char *, int);
char	*my_strcat(char *, char *);

#endif /* !HEADER_H_ */
