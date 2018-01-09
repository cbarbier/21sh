/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Z1sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2018/01/09 19:45:39 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z1SH_H
# define Z1SH_H
# include "../libft/includes/libft.h"
# include <curses.h>
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <math.h>
# define DEBUG					1
# define TRUE					1
# define FALSE					0
# define MAX_KEY_STRING_LENGTH	9
# define NB_KEYS				20
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
# define KEY_CODE_ALT_S			17
# define KEY_CODE_CTRL_U		18
# define KEY_CODE_CTRL_C		19
# define HIST_LEN				5
# define MAX(A, B)	((A) > (B) ? (A) : (B))
# define MIN(A, B)	((A) < (B) ? (A) : (B))

typedef struct	s_hist
{
	t_list		*line;
	int			sel;
}				t_hist;
typedef struct	s_input
{
	char		c;
	int			del;
	int			x;
	int			y;
}				t_input;
typedef struct	s_cursor
{
	int		sx;
	int		sy;
	int		x;
	int		y;
}				t_cursor;
struct s_21sh;
typedef struct	s_key_func
{
	int			k;
	int			(*f_is)(char *);
	int			(*f)(struct s_21sh *);
}				t_key_func;
typedef struct	s_21sh
{
	struct termios	term;
	char			*prmpt;
	char			buff[MAX_KEY_STRING_LENGTH + 1];
	char			*str;
	t_list			*cmd;
	int				n;
	t_list			*line;
	t_input			end;
	t_list			*save;
	t_list			*hist[HIST_LEN];
	int				histpos;
	int				ttyfd;
	t_cursor		curs;
	t_cursor		eol;
	int				run;
	int				co;
	int				li;
	int				ln;
	int				beg_sel;
	int				end_sel;
}				t_21sh;
/*
** 	INIT FUNCTIONS
*/
int				init_termcaps(t_21sh *e);
int				reset_terminal(t_21sh *e);
int				init_21sh(t_21sh *e, int argc, char **argv);
int				init_loop(t_21sh *e);
int				next_loop(t_21sh *e, char *str, int (*f)(t_21sh*));
t_21sh			*get_e(t_21sh *e);
/*
** 	CORE FUNCTIONS
*/

int				core_21sh(t_21sh *e);
int				exit_21sh(t_21sh *e, int n);
/*
** 	PARSING FUNCTIONS
*/
int				quoting(t_list *l);
char			*ft_lsttostr(t_list *l);
/*
** 	EDIT LINE FUNCTIONS
*/
int				set_prmpt(t_21sh *e, char *str);
int				print_prmpt(t_21sh *e);
t_input			*get_input(t_list *l, int n);
int				wrapper(int (*f)(t_21sh *e), t_21sh *e);
int				key_apply_func(t_21sh *e);
t_key_func		*key_tab(void);
void			del_line(void *ct, size_t size);
int				putline(t_21sh *e, t_list *l);
int				refresh_line(t_21sh *e, t_list *l);
int				get_eol(t_21sh *e);
int				myput(int c);
void			resize_handler(int sig);
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
int				ctrl_c_handler(t_21sh *e);
int				ctrl_d_handler(t_21sh *e);
int				ctrl_u_handler(t_21sh *e);
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
int				select_mode(t_21sh *e);
/*
** 	TEST KEY FUNCTIONS
*/
int				key_is_ret(char *buff);
int				key_is_ctrl_c(char *buff);
int				key_is_ctrl_d(char *buff);
int				key_is_ctrl_u(char *buff);
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
int				key_is_alt_s(char *buff);
/*
** 	DEBUG FUNCTIONS
*/
int				put_buff(t_21sh *e, char *buff);
#endif
