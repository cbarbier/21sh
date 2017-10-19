/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:33:55 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/19 18:35:18 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				key_get(char *buff)
{
	int					i;
	static t_kcheck		ftab[] = {
		{KEY_CODE_CTRL_D, 0},
		{KEY_CODE_CTRL_R, 0}
	};

	(void)buff;
	(void)i;
	return ((int)ftab[0].f);
}
