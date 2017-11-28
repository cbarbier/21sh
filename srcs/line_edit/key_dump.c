/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:33:55 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/28 18:18:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_key_func		*key_tab(void)
{
	static t_key_func	ftab[] = {
		{KEY_CODE_CTRL_D,		&key_is_ctrl_d,			&ctrl_d_handler},
		{KEY_CODE_CTRL_R,		&key_is_ctrl_r,			&ctrl_r_handler},
		{KEY_CODE_TAB,			&key_is_tab,			&tab_handler},
		{KEY_CODE_HOME,			&key_is_home,			&go_home},
		{KEY_CODE_END,			&key_is_end,			&go_end},
		{KEY_CODE_UP,			&key_is_up,				&history_back},
		{KEY_CODE_DOWN,			&key_is_down,			&history_next},
		{KEY_CODE_LEFT,			&key_is_left,			&curs_left},
		{KEY_CODE_RIGHT,		&key_is_right,			&curs_right},
		{KEY_CODE_RET,			&key_is_ret,			&ret_handler},
		{KEY_CODE_DEL,			&key_is_del,			&del_char},
		{KEY_CODE_ALT_UP,		&key_is_alt_up,			&go_last_line},
		{KEY_CODE_ALT_DOWN,		&key_is_alt_down,		&go_next_line},
		{KEY_CODE_ALT_LEFT,		&key_is_alt_left,		&go_last_word},
		{KEY_CODE_ALT_RIGHT,	&key_is_alt_right,		&go_next_word},
		{KEY_CODE_ASCII,		&key_is_char,			&ins_char},
		{KEY_CODE_NONE,			0, 						0}
	};

	return (ftab);
}

int				key_apply_func(t_21sh *e)
{
	t_key_func			*ftab;
	int					i;

	ftab = key_tab();
	i = 0;
	while (ftab[i].f)
	{
		if (ftab[i].f_is(e->buff) == TRUE)
		{
			ftab[i].f(e);
			return (ftab[i].k);
		}
		i++;
	}
	ft_fprintf(e->ttyfd, "NO VALID KEY\n");
	return (KEY_CODE_NONE);
}
