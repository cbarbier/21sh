/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/11 21:30:11 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				refresh_line(t_21sh *e, t_list *l)
{
	e->ln = ft_lstlen(e->line);
	ft_fprintf(e->ttyfd, "selecting DBUG beg=%d & end=%d\n",
			e->beg_sel, e->end_sel);
	tputs(tgoto(tgetstr("cm", 0), e->curs.sx - 1, e->curs.sy - 1), 1, myput);
	if (get_eol(e) == -1)
		return (-1);
	tputs(tgetstr("cd", 0), 1, myput);
	putline(e, l);
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	return (0);
}

int				get_eol(t_21sh *e)
{
	int			n;
	int			d;

	d = e->curs.sy + ((e->curs.sx + e->ln) / e->co);
	n = e->curs.sy;
	tputs(tgetstr("cd", 0), 1, myput);
	ft_fprintf(e->ttyfd, "gotta jump %d lines | height : %d\n", d, d - n);
	if ((int)ft_lstlen(e->line) > e->li * e->co)
	{
		ft_fprintf(e->ttyfd, "command line way too big\n", d);
		return (-1);
	}
	while (n++ < d)
	{
		tputs(tgetstr("do", 0), 1, myput);
		if (n > e->li)
		{
			e->curs.sy--;
			e->curs.y--;
		}
	}
	tputs(tgoto(tgetstr("cm", 0), e->curs.sx - 1, e->curs.sy - 1), 1, myput);
	return (d);
}

int				putline(t_21sh *e, t_list *l)
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

static int		ft_lstaddat(t_list **al, t_list *new, int i)
{
	t_list		*l;
	t_list		*tmp;

	if (!i || !*al)
	{
		new->next = *al;
		*al = new;
		return (0);
	}
	l = *al;
	while (l->next && --i)
		l = l->next;
	tmp = l->next;
	l->next = new;
	new->next = tmp;
	return (0);
}

int				ins_char(t_21sh *e)
{
	int			i;
	t_list		*new;
	t_input		in;

	in.c = *e->buff;
	in.del = 0;
	i = e->curs.x - e->curs.sx + (e->curs.y - e->curs.sy) * e->co;
	ft_fprintf(e->ttyfd, "function ins char {{ %c }} at %i\n",
			*e->buff, i);
	ft_fprintf(e->ttyfd, "END x %d y %d\n",
			(e->curs.sx + e->ln)
			% e->co, e->curs.sy + e->ln / e->co);
	if (!(new = ft_lstnew(&in, sizeof(t_input))))
		return (1);
	ft_lstaddat(&e->line, new, i);
	e->ln++;
	e->beg_sel = -2;
	if (!(i = refresh_line(e, e->line)))
		curs_right(e);
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } START @ { %d : %d }\n",
			e->curs.x, e->curs.y, e->curs.sx, e->curs.sy);
	return (1);
}
