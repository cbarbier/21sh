/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/20 11:03:25 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  F21SH_H
# define F21SH_H
# include "../libft/includes/libft.h"
# include <curses.h>
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <math.h>
# define TRUE			1
# define FALSE			0
# define DEBUG			1
# define MAX_KEY_STRING_LENGTH	6
# define KEY_CODE_OTHER		-1
# define KEY_CODE_NONE		0
# define KEY_CODE_CTRL_D 	1
# define KEY_CODE_CTRL_R	2
# define KEY_CODE_TAB		3
# define KEY_CODE_HOME		4
# define KEY_CODE_END		5
# define KEY_CODE_PUP		6
# define KEY_CODE_PDOWN		7
# define KEY_CODE_UP		8
# define KEY_CODE_DOWN		9
# define KEY_CODE_LEFT		10
# define KEY_CODE_RIGHT		11
typedef struct	s_kcheck
{
	int			k;
	int			(*f)(char *);
}				t_kcheck;
typedef struct	s_21sh
{
}				t_21sh;
int			key_get(char *buff);
/*
** 	CORE FUNCTIONS
*/
/*
** 	KEY FUNCTIONS
*/
int				key_is_ctrl_d(char *buff);
int				key_is_ctrl_r(char *buff);
int				key_is_tab(char *buff);
int				key_is_home(char *buff);
int				key_is_end(char *buff);
int				key_is_pup(char *buff);
int				key_is_pdown(char *buff);
int				key_is_up(char *buff);
int				key_is_down(char *buff);
int				key_is_left(char *buff);
int				key_is_right(char *buff);
/*
** 	DEBUG FUNCTIONS
*/
#endif
