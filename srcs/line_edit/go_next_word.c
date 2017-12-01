/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_next_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/01 04:44:07 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				lst_next_word(t_21sh *e, t_list *l, int n)
{
	int			i;

	i = 0;
	while (l && (i++ < n || !ft_strchr(" \t", ((t_input *)l->content)->c)))
		l = l->next;
	ft_fprintf(e->ttyfd, "end of curent word i=%d\n", i);
	while (l && ft_strchr(" \t", ((t_input *)l->content)->c) && i++)
		l = l->next;
	return (l ? i : -1);
}

int				go_next_word(t_21sh *e)
{
	int				n;
	int				i;

	n = e->curs.x - (int)ft_strlen(e->prmpt) - 1 +
		(e->curs.y - e->curs.sy) * e->co;
	ft_fprintf(e->ttyfd, "function  go next word cursor at n=%d\n", n);
	if ((i = lst_next_word(e, e->line, n)) == -1)
	{
		ft_fprintf(e->ttyfd, "can't find next word\n");
		return (0);
	}
	ft_fprintf(e->ttyfd, "next word indice i=%d\n", i);
	e->curs.x = ((int)ft_strlen(e->prmpt) + i) % e->co;
	e->curs.y = e->curs.sy + ((int)ft_strlen(e->prmpt) + i) / e->co;
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	if (e->beg_sel != -2)
	{
		e->beg_sel = -2;
		refresh_line(e, e->line);
	}
	return (0);
}
