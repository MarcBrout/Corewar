/*
** header.h for header
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 15:32:59 2016
** Last update Tue Mar 22 14:58:09 2016 marel_m
*/

#ifndef HEADER_H_
# define HEADER_H_

# include "op.h"
# include "my.h"

# include <unistd.h>

/*
** Debug includes
*/

# include <stdio.h>

# define UNUSED __attribute__((__unused__))
# define NB_INSTRUCTIONS 16

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

typedef struct		s_list_label
{
  char			*name;
  int			pos;
  struct s_list_label	*next;
  struct s_list_label	*prev;
}			t_list_label;

typedef struct		s_instruc
{
  int			lenght;
  t_list_instruc	*root;
  int			lenght_label;
  t_list_label		*lab;
  int			nb_l;
}			t_instruc;

enum			three_args
  {
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    LDI,
    STI,
    LLDI,
    MAX_THREE_ARGS
  };

typedef struct		s_three_args
{
  int			ins;
  int			(*ft_three)(t_instruc *, t_list_instruc *, char *);
}			t_three_args;

typedef struct  s_tabinstr
{
  int           (**tabinstr)(t_info *, int);
}               t_tabinstr;

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
int			check_comment(t_header *, t_instruc *, char *);
int			check_instructions(t_instruc *, int);
int			check_instruc_label(t_instruc *, t_list_instruc *,
					    char *, int);
int			check_epure_line(char *, int);
int			check_which_instruc(t_instruc *, t_list_instruc *,
					    char *, int);
int			check_stock_good_args(t_instruc *, t_list_instruc *,
					      char *, int);
void			print_list(t_instruc *);
int			check_direct_arg(t_instruc *, t_list_instruc *,
					 char *, int);
int			check_registre_arg(t_list_instruc *, char *, int);
int			check_indirect_arg(t_instruc *, t_list_instruc *,
					   char *, int);
int			stock_args(t_list_instruc *, char *, int);
int			check_end_instruc(char *, int);
int			check_if_label_exist(t_instruc *);
int			create_list_label(t_instruc *);
t_list_label		*add_list_after_label(t_instruc *);
int			verif_three_args(t_instruc *, t_list_instruc *,
					 char *, int);
t_three_args		*init_tab_three_args();
int			if_comment_text(char *);
int			check_line(char *);

/*
** Parser functions
*/

int	parser(char *, t_header *, t_instruc *);
int	write_header(int, t_header *);
int	write_code(int, t_instruc *, t_tabinstr *, char **);
void	set_line_null(char *, int);
int	convert_littleend_to_bigend_int(int);
int	convert_littleend_to_bigend_short(int);
int	create_file(char *);

/*
** TOOLS
*/

void	free_tab(char **);
char	*my_strncpy(char *, char *, int);
char	*my_strndup(char *, int);
char	*my_strcat(char *, char *);
void	my_put_nbr_error(int);

/*
** FREE
*/

void	free_list(t_instruc *);

/*
** Error
*/

void	malloc_fail();
void	file_wrong(char *);
void	no_exist_label(t_list_label *);
void	synthax_error(t_instruc *);

/*
** Instruction functions
*/

int	w_reg(int, char *);
int	w_int(int, char *);
int	w_short(int, char *);
char	w_coding_byte(int, t_info *);
int	w_live(t_info *, int);
int	w_ld(t_info *, int);
int	w_st(t_info *, int);
int	w_add(t_info *, int);
int	w_sub(t_info *, int);
int	w_and(t_info *, int);
int	w_or(t_info *, int);
int	w_xor(t_info *, int);
int	w_zjmp(t_info *, int);
int	w_ldi(t_info *, int);
int	w_sti(t_info *, int);
int	w_fork(t_info *, int);
int	w_lld(t_info *, int);
int	w_lldi(t_info *, int);
int	w_lfork(t_info *, int);
int	w_aff(t_info *, int);

#endif /* !HEADER_H_ */
