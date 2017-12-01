/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/01 18:22:16 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				next_loop(t_21sh *e, char *str, int (*f)(t_21sh *))
{
	int			ret;

	e->beg_sel = -2;
	ret = refresh_line(e, e->line);
	reset_terminal(e);
	ft_printf("\n%s\n", str);
	if (f)
		f(e);
	if (e->run)
		init_loop(e);
	return (ret);
}

int				ret_handler(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function ret handler\n");
	next_loop(e, "parsing && processing the commands  blabla bla", 0);
	return (0);
}

