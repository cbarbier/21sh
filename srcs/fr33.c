/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr33.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:52:15 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/07 13:20:08 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
** dont forget to free the prmpt;
*/

static int			fr33(t_21sh *e)
{
	int			i;

	(void)e;
	i = 0;
	return (0);
}

int					exit_21sh(t_21sh *e, int n)
{
	reset_terminal(e);
	fr33(e);
	exit(n);
	return (0);
}
