/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/14 15:54:14 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

static int		lst_next_line(t_21sh *e, t_list *l, int n)
{
	int			i;
	t_input		*cur;
	t_input		*in;

	i = 0;
	while (l && i++ < n)
		l = l->next;
	cur = (l ? (t_input *)l->content : 0);
	ft_fprintf(e->ttyfd, "pos i= %i ==========> cur [%d:%d] %c\n", i, (cur ? cur->x : 0), (l ? cur->y : 0), (l ? cur->c : '0'));
	while (l)
	{
		in = (t_input *)l->content;
		ft_fprintf(e->ttyfd, "pos i= %i in [%d:%d] %c\n", i, (in ? in->x : 0), (l ? in->y : 0), (l ? in->c : '0'));
		if (in->y == cur->y + 1 && (in->x == cur->x || in->c == '\n'))
		{
			ft_fprintf(e->ttyfd, "found pos i= %i in [%d:%d] %c\n", i, (in ? in->x : 0), (l ? in->y : 0), (l ? in->c : '0'));
			return (i);
		}
		l = l->next;
		i++;
	}
	if (in && in->y == e->end.y)
		return (e->ln + 1);
	return (-1);
}

int				go_next_line(t_21sh *e)
{
	int				i;

	ft_fprintf(e->ttyfd, "function go next line from %i\n", e->n);
	if ((i = lst_next_line(e, e->line, e->n)) == -1)
	{
		ft_fprintf(e->ttyfd, "next line not found\n");
		return (0);
	}
	ft_fprintf(e->ttyfd, "i = %d\n", i);
	e->n = i;
	curs_left(e);
	if (e->beg_sel != -2)
		e->end_sel = i;
	return (0);
}
