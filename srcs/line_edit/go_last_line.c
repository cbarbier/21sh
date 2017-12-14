/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_last_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/14 15:55:07 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

static t_input		*get_cur(t_21sh *e, t_list *l, int n)
{
	if (!l)
		return (0);
	while (l && n--)
		l = l->next;
	return ((l ? (t_input *)l->content : &e->end));
}

static int			lst_last_line(t_21sh *e, t_list *l, int n)
{
	int			i;
	t_input		*cur;
	t_input		*in;

	i = 0;
	if (!(cur = get_cur(e, l, n)) || !cur->y
			|| (cur->x < e->curs.sx && cur->y == 1))
		return (-1);
	ft_fprintf(e->ttyfd, "func last line pos i= %d cur ==================> [%d:%d]\n", e->n, cur ? cur->x : -1, cur ? cur->y : -1);
	while (l && i < n)
	{
		in = (t_input *)l->content;
		ft_fprintf(e->ttyfd, "i%d in [%d:%d] in->c %c\n", i, in->x, in->y, (in ? in->c : '0'));
		if (in->y == cur->y - 1 && ((in->x == cur->x) || in->c == '\n'))
			break ;
		if ((l = l->next))
			i++;
	}
	ft_fprintf(e->ttyfd, "last line pos ret= %i char %c\n", i, (in ? in->c : '0'));
	return (i - (cur == &e->end));
}

int					go_last_line(t_21sh *e)
{
	int		i;

	ft_fprintf(e->ttyfd, "function go last line\n");
	if ((i = lst_last_line(e, e->line, e->n)) == -1)
	{
		ft_fprintf(e->ttyfd, "can't go last line\n");
		return (0);
	}
	e->n = i;
	if (e->beg_sel != -2)
		e->beg_sel = i;
	return (0);
}
