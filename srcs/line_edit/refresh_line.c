/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/14 16:10:48 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

static int	make_room_helper(t_21sh *e, t_cursor *curs, t_input *in, int n)
{

	if (n == e->n)
	{
		ft_fprintf(e->ttyfd, "set cursor %d : %d\n", curs->x, curs->y);
		e->curs.x = (!curs->y ? e->curs.sx : 0) + curs->x;
		e->curs.y = e->curs.sy + curs->y;
	}
	if (curs->x++ == e->co - (!curs->y ? e->curs.sx : 0)
		|| (in && in->c == '\n'))
	{
		if (++curs->y > e->li)
			return (-1);
		if (e->curs.sy + curs->y > e->li)
		{
			--e->curs.sy;
			e->curs.y--;
		}
		curs->x = 1;
		tputs(tgetstr("do", 0), 1, myput);
	}
	return (0);
}

static int	make_room(t_21sh *e, t_list *l)
{
	int			n;
	t_cursor	curs;
	t_input		*in;

	ft_bzero(&curs, sizeof(t_cursor));
	n = -1;
	while (++n <= e->ln)
	{
		ft_fprintf(e->ttyfd, "TEST n %d / %d ", n, e->ln);
		in = 0;
		if (l)
		{
			in = (t_input *)l->content;
			in->x = (!curs.y ? e->curs.sx : 0) + curs.x;
			in->y = curs.y;
			l = l->next;
		}
		if (make_room_helper(e, &curs, in, n) == -1)
			return (-1);
	}
	e->end.x = (!curs.y ? e->curs.sx : 0) + curs.x;
	e->end.y = curs.y;
	tputs(tgoto(tgetstr("cm", 0), e->curs.sx - 1, e->curs.sy - 1), 1, myput);
	return (0);
}

int		refresh_line(t_21sh *e, t_list *l)
{
	e->ln = ft_lstlen(e->line);
	ft_fprintf(e->ttyfd, "refresh line DBUG e->n %d beg=%d & end=%d\n", e->n,
			e->beg_sel, e->end_sel);
	tputs(tgoto(tgetstr("cm", 0), e->curs.sx - 1, e->curs.sy - 1), 1, myput);
	if (make_room(e, l) == -1)
		return (-1);
	tputs(tgetstr("cd", 0), 1, myput);
	putline(e, l);
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	return (0);
}

int		putline(t_21sh *e, t_list *l)
{
	t_input			*in;
	int				i;

	i = 0;
	while (l)
	{
		in = (t_input *)l->content;
		if (e->beg_sel != -2 && i >= MIN(e->beg_sel, e->end_sel)
				&& i <= MAX(e->beg_sel, e->end_sel))
			ft_printf("\033[35;46m%c{no}", in->c);
		else
			write(1, &in->c, 1);
		i++;
		l = l->next;
	}
	return (0);
}
