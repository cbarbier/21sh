/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr33.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:52:15 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/05 18:14:30 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

void				del_line(void *ct, size_t size)
{
	(void)size;
	ft_memdel(&ct);
}

/*
** dont forget to free the prmpt;
*/

static int			fr33(t_21sh *e)
{
	int			i;

	ft_lstdel(&e->line, del_line);
	ft_lstdel(&e->save, del_line);
	i = 0;
	while (i < HIST_LEN)
		ft_lstdel(&e->hist[i++], del_line);
	return (0);
}

int					exit_21sh(t_21sh *e, int n)
{
	reset_terminal(e);
	fr33(e);
	exit(n);
	return (0);
}
