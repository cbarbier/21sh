/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_last_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/12 16:59:20 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

int				lst_last_word(t_21sh *e, t_list *l, int n)
{
	int			i;
	int			sol;
	int			lastc;
	int			curc;

	i = 0;
	sol = -1;
	curc = ' ';
	while (l && i < n)
	{
		lastc = curc;
		curc = ((t_input *)l->content)->c;
		if (ft_strchr(" \t\n", lastc) && !ft_strchr(" \t\n", curc))
		{
			ft_fprintf(e->ttyfd, "found a beginig of a word i=%d\n", i);
			sol = i;
		}
		i++;
		l = l->next;
	}
	return (sol);
}

int				go_last_word(t_21sh *e)
{
	int				i;

	ft_fprintf(e->ttyfd, "function  go last word cursor at n=%d\n", e->n);
	if ((i = lst_last_word(e, e->line, e->n)) == -1)
	{
		ft_fprintf(e->ttyfd, "can't find last word\n");
		return (0);
	}
	ft_fprintf(e->ttyfd, "last word indice i=%d\n", i);
	e->n = i;
	if (e->beg_sel != -2)
		e->end_sel = e->n;
	return (0);
}
