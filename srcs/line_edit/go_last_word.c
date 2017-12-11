/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_last_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/11 21:27:49 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				lst_last_word(t_21sh *e, t_list *l, int n)
{
	int			i;
	int			sol;
	int			lastc;
	int			curc;

	(void)e;
	i = 1;
	sol = -1;
	curc = ' ';
	while (l && i < n)
	{
		lastc = curc;
		curc = ((t_input *)l->content)->c;
		if (ft_strchr(" \t", lastc) && !ft_strchr(" \t", curc))
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
	int				n;
	int				i;

	n = e->curs.x - e->curs.sx + (e->curs.y - e->curs.sy) * e->co;
	ft_fprintf(e->ttyfd, "function  go last word cursor at n=%d\n", n);
	if ((i = lst_last_word(e, e->line, n)) == -1)
	{
		ft_fprintf(e->ttyfd, "can't find last word\n");
		return (0);
	}
	ft_fprintf(e->ttyfd, "last word indice i=%d\n", i);
	e->curs.x = (e->curs.sx - 1 + i) % e->co;
	e->curs.y = e->curs.sy + (e->curs.sx - 1 + i) / e->co;
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	if (e->beg_sel != -2)
		e->beg_sel = -2;
	return (0);
}
