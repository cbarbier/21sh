/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:17:26 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/27 17:01:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				history_next(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function history next\n");
	tputs(tgetstr("do", 0), 1, myput);
	return (0);
}
