/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:33:55 by cbarbier          #+#    #+#             */
/*   Updated: 2018/01/09 14:12:34 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

t_key_func		*key_tab(void)
{
	static t_key_func	ftab[] = {
		{KEY_CODE_CTRL_D, &key_is_ctrl_d, &ctrl_d_handler},
		{KEY_CODE_HOME, &key_is_home, &go_home},
		{KEY_CODE_END, &key_is_end, &go_end},
		{KEY_CODE_UP, &key_is_up, &history_back},
		{KEY_CODE_DOWN, &key_is_down, &history_next},
		{KEY_CODE_LEFT, &key_is_left, &curs_left},
		{KEY_CODE_RIGHT, &key_is_right, &curs_right},
		{KEY_CODE_RET, &key_is_ret, &ret_handler},
		{KEY_CODE_DEL, &key_is_del, &del_char},
		{KEY_CODE_ALT_UP, &key_is_alt_up, &go_last_line},
		{KEY_CODE_ALT_DOWN, &key_is_alt_down, &go_next_line},
		{KEY_CODE_ALT_LEFT, &key_is_alt_left, &go_last_word},
		{KEY_CODE_ALT_RIGHT, &key_is_alt_right, &go_next_word},
		{KEY_CODE_ASCII, &key_is_char, &ins_char},
		{KEY_CODE_ALT_X, &key_is_alt_x, &do_cut},
		{KEY_CODE_ALT_C, &key_is_alt_c, &do_copy},
		{KEY_CODE_ALT_V, &key_is_alt_v, &do_paste},
		{KEY_CODE_ALT_S, &key_is_alt_s, &select_mode},
		{KEY_CODE_CTRL_U, &key_is_ctrl_u, &ctrl_u_handler}
	};

	return (ftab);
}

int				key_apply_func(t_21sh *e)
{
	t_key_func			*ftab;
	int					i;

	ftab = key_tab();
	i = 0;
	while (i < NB_KEYS)
	{
		if (ftab[i].f_is(e->buff) == TRUE)
		{
			wrapper(ftab[i].f, e);
			return (ftab[i].k);
		}
		i++;
	}
	ft_fprintf(e->ttyfd, "NO VALID KEY\n");
	return (-1);
}
