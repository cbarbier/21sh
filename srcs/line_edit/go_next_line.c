/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/13 22:20:39 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

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
	in = 0;
	while (l && ++i && (in = (t_input *)l->content)
			&& in->y != cur->y + 1 && in->c != '\n')
		l = l->next;
	ft_fprintf(e->ttyfd, "end of line i= %i char %c\n", i, (in ? in->c : '0'));
	l = (l ? l->next : l);
	if (l && in && cur->y == in->y - 1 && in->x == cur->x)
		return (i);
	in = 0;
	while (l)
	{
		in = (t_input *)l->content;
		ft_fprintf(e->ttyfd, "pos i= %i in [%d:%d] %c\n", i, (in ? in->x : 0), (l ? in->y : 0), (l ? in->c : '0'));
	   	if (in->x == cur->x - 1 || in->c == '\n')
			break;
		if ((l = l->next))
			i++;
	}
	ft_fprintf(e->ttyfd, "next line pos i= %i char %c\n", i, (in ? in->c : '0'));
	return (in ? i - (cur->c =='\n' && in->c == '\n') : -1);
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
	if (e->beg_sel != -2)
		e->end_sel = i;
	return (0);
}
