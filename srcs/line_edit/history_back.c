/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:16:42 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/11 21:30:34 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				history_back(t_21sh *e)
{
	int			ret;

	ft_fprintf(e->ttyfd, "function history back\n");
	if (e->beg_sel != -2)
		return (select_up(e));
	if (e->histpos + 1 == HIST_LEN || !e->hist[e->histpos + 1])
	{
		e->histpos = -1;
		ft_fprintf(e->ttyfd, "end of hist\n");
		return (0);
	}
	ft_lstdel(&e->line, del_line);
	e->line = ft_lstcpy(e->hist[++e->histpos], sizeof(t_input));
	ret = refresh_line(e, e->line);
	go_end(e);
	return (1);
}
