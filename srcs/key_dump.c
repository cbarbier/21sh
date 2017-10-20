/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:33:55 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/20 10:31:20 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				key_get(char *buff)
{
	int					i;
	static t_kcheck		ftab[] = {
		{0,					0},
		{KEY_CODE_CTRL_D,	&key_is_ctrl_d},
		{KEY_CODE_CTRL_R,	&key_is_ctrl_r}
		{KEY_CODE_TAB,		&key_is_tab},
		{KEY_CODE_HOME,		&key_is_home},
		{KEY_CODE_END,		&key_is_end},
		{KEY_CODE_PUP, 		&key_is_pup},
		{KEY_CODE_UP,		&key_is_up},
		{KEY_CODE_DOWN,		&key_is_down},
		{KEY_CODE_LEFT,		&key_is_left},
		{KEY_CODE_RIGHT,	&key_is_right},
		{KEY_CODE_RET,		&key_is_ret},
		{KEY_CODE_NONE,		0},
	};
	i = -1;
	while (ftab[++i].f)
		if (ftab[i].f(buff) == TRUE)
			return (ftab[i].k);
	return (KEY_CODE_OTHER);
}
