/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/28 18:21:41 by cbarbier         ###   ########.fr       */
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
# define KEY_CODE_CTRL_D		0
# define KEY_CODE_CTRL_R		1
# define KEY_CODE_TAB			2
# define KEY_CODE_HOME			3
# define KEY_CODE_END			4
# define KEY_CODE_UP			5
# define KEY_CODE_DOWN			6
# define KEY_CODE_LEFT			7
# define KEY_CODE_RIGHT			8
# define KEY_CODE_RET			9
# define KEY_CODE_DEL			10
# define KEY_CODE_ALT_UP		11
# define KEY_CODE_ALT_DOWN		12
# define KEY_CODE_ALT_LEFT		13
# define KEY_CODE_ALT_RIGHT		14
# define KEY_CODE_ASCII			15
# define KEY_CODE_NONE			16
typedef struct	s_cursor
{
	int		sx;
	int		sy;
	int		x;
	int		y;
}				t_cursor;
struct	s_21sh;
typedef struct	s_key_func
{
	int			k;
	int			(*f_is)(char *);
	int			(*f)(struct s_21sh *);
}				t_key_func;
typedef struct	s_21sh
{
	struct termios	term;
	char			prmpt[9];
	char			buff[MAX_KEY_STRING_LENGTH + 1];
	t_list			*line;
	int				len;
	int				ttyfd;
	t_cursor		curs;
	t_cursor		eol;
	int				run;
	int				co;
	int				li;
	int				ln;
}					t_21sh;
/*
** 	INIT FUNCTIONS
*/
int				init_termcaps(t_21sh *e);
int				reset_terminal(t_21sh *e);
int				init_21sh(t_21sh *e, int argc, char **argv);
/*
** 	CORE FUNCTIONS
*/
int				myput(int c);

t_key_func		*key_tab(void);
int				key_apply_func(t_21sh *e);
int				core_21sh(t_21sh *e);
int				exit_21sh(t_21sh *e);
void			del_line(void *ct, size_t size);
/*
** 	EDIT LINE FUNCTIONS
*/
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
/*
** 	DEBUG FUNCTIONS
*/
int				put_buff(t_21sh *e, char *buff);
#endif
