/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr33.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:52:15 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/28 15:42:55 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				del_line(void *ct, size_t size)
{
	(void)size;
	ft_memdel(&ct);
}

static int			fr33(t_21sh *e)
{
	(void)e;
	return (0);
}

int					exit_21sh(t_21sh *e)
{
	reset_terminal(e);
	fr33(e);
	exit(1);
	return (0);
}
