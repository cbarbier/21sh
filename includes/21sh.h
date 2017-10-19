/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 14:12:45 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/19 18:32:14 by cbarbier         ###   ########.fr       */
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
# define KEY_CODE_CTRL_D 	0
# define KEY_CODE_CTRL_R	1
# define KEY_CODE_TAB		2
# define KEY_CODE_HOME		3
# define KEY_CODE_END		4
# define KEY_CODE_PUP		5
# define KEY_CODE_PDOWN		6
# define KEY_CODE_UP		7
# define KEY_CODE_DOWN		8
# define KEY_CODE_LEFT		9
# define KEY_CODE_RIGHT		10
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
** 	DEBUG FUNCTIONS
*/
#endif
