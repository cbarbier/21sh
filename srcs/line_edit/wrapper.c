/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:21:20 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/14 16:11:35 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

int			wrapper(int (*f)(t_21sh *), t_21sh *e)
{
	int			ret;
	int			error_refresh;

	ret = f(e);
	error_refresh = 0;
	if (!ret)
		error_refresh = refresh_line(e, e->line);
	if (error_refresh == -1)
	{
		tputs(tgoto(tgetstr("cm", 0), 0, 0), 1, myput);
		tputs(tgetstr("cd", 0), 1, myput);
		PRMPT("fuck$ \0", 7);
		return (next_loop(e, "Warning: an error occured,\
					so let's REFRESH ∆∆∆ \n", 0));
	}
	return (0);
}
