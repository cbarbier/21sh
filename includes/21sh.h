/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/07 17:22:04 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  F21SH_H
# define F21SH_H
# include "../libft/includes/libft.h"
# include <curses.h>
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <signal.h>	  
# include <math.h>
# define TRUE					1
# define FALSE					0
# define DEBUG					1
# define MAX_KEY_STRING_LENGTH	9
# define NB_KEYS				21
# define KEY_CODE_CTRL_D		0
# define KEY_CODE_HOME			1
# define KEY_CODE_END			2
# define KEY_CODE_UP			3
# define KEY_CODE_DOWN			4
# define KEY_CODE_LEFT			5
# define KEY_CODE_RIGHT			6
# define KEY_CODE_RET			7
# define KEY_CODE_DEL			8
# define KEY_CODE_ALT_UP		9
# define KEY_CODE_ALT_DOWN		10
# define KEY_CODE_ALT_LEFT		11
# define KEY_CODE_ALT_RIGHT		12
# define KEY_CODE_ASCII			13
# define KEY_CODE_ALT_X			14
# define KEY_CODE_ALT_C			15
# define KEY_CODE_ALT_V			16
# define KEY_CODE_SHFT_UP		17
# define KEY_CODE_SHFT_DOWN		18
# define KEY_CODE_SHFT_LEFT		19
# define KEY_CODE_SHFT_RIGHT	20
# define HIST_LEN				5
# define MAX(A, B)	((A) > (B) ? (A) : (B)) 
# define MIN(A, B)	((A) < (B) ? (A) : (B)) 
# define RFRSH_LINE				0b1
# define RFRSH_CURSOR			0b10
struct	s_21sh;
typedef struct	s_key_func
{
	int			k;
	int			(*f_is)(char *);
	int			(*f)(struct s_21sh *);
}				t_key_func;
typedef struct	s_cursor
{
	int		p;
	int		sx;
	int		sy;
	int		x;
	int		y;
}				t_cursor;
typedef struct t_term
{
	int			li;
	int			co;
}				t_term;
typedef struct	s_input
{
	char		*txt;
	int			ln;
}				t_input;
typedef struct	s_21sh
{
	struct termios	term;
	int				ttyfd;
	char			buff[MAX_KEY_STRING_LENGTH + 1];
	char			*prmpt;
	t_term			t;
	t_cursor		c;
	t_input			in;
	int				run;
}				t_21sh;
/*
** 	INIT FUNCTIONS
*/
int				init_termcaps(t_21sh *e);
int				reset_terminal(t_21sh *e);
int				init_21sh(t_21sh *e, int argc, char **argv);
int				init_loop(t_21sh *e);
t_21sh			*get_e(t_21sh *e);
/*
** 	CORE FUNCTIONS
*/

int				core_21sh(t_21sh *e);
int				exit_21sh(t_21sh *e, int n);
/*
** 	PARSING FUNCTIONS
*/
/*
** 	EDIT LINE FUNCTIONS
*/
int				refresh_line(t_21sh *e);
int				keyfunc_wrapper(int (*f)(t_21sh*), t_21sh *e);
int				key_apply_func(t_21sh *e);
t_key_func		*key_tab(void);
int				myput(int c);
void			resize_handler(int);
int				get_cursor_xy(t_21sh *e, t_cursor *curs);
int				print_line(char *line, int i, int len);
int				curs_right(t_21sh *e);
int				curs_left(t_21sh *e);
int				del_char(t_21sh *e);
int				ins_char(t_21sh *e);
int				go_home(t_21sh *e);
int				go_end(t_21sh *e);
int				go_next_word(t_21sh *e);
int				go_last_word(t_21sh *e);
int				go_next_line(t_21sh *e);
int				go_last_line(t_21sh *e);
int				ctrl_d_handler(t_21sh *e);
int				ctrl_r_handler(t_21sh *e);
int				ret_handler(t_21sh *e);
int				tab_handler(t_21sh *e);
int				history_back(t_21sh *e);
int				history_next(t_21sh *e);
int				do_cut(t_21sh *e);
int				do_copy(t_21sh *e);
int				do_paste(t_21sh *e);
int				select_right(t_21sh *e);
int				select_left(t_21sh *e);
int				select_up(t_21sh *e);
int				select_down(t_21sh *e);
/*
** 	TEST KEY FUNCTIONS
*/
int				key_is_ret(char *buff);
int				key_is_ctrl_d(char *buff);
int				key_is_ctrl_r(char *buff);
int				key_is_tab(char *buff);
int				key_is_home(char *buff);
int				key_is_end(char *buff);
int				key_is_up(char *buff);
int				key_is_down(char *buff);
int				key_is_left(char *buff);
int				key_is_right(char *buff);
int				key_is_del(char *buff);
int				key_is_alt_up(char *buff);
int				key_is_alt_down(char *buff);
int				key_is_alt_left(char *buff);
int				key_is_alt_right(char *buff);
int				key_is_char(char *buff);
int				key_is_alt_x(char *buff);
int				key_is_alt_c(char *buff);
int				key_is_alt_v(char *buff);
int				key_is_shft_up(char *buff);
int				key_is_shft_down(char *buff);
int				key_is_shft_left(char *buff);
int				key_is_shft_right(char *buff);
/*
** 	DEBUG FUNCTIONS
*/
int				put_buff(t_21sh *e, char *buff);
#endif
