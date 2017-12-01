/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/01 18:22:48 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				get_eol(t_21sh *e, t_list *tmp)
{
	int			n;
	int			d;

	(void)tmp;
	n = e->ln + (int)ft_strlen(e->prmpt);
	d = e->curs.sy + (n / e->co);
	n = e->curs.sy;
	tputs(tgetstr("cd", 0), 1, myput);
	ft_fprintf(e->ttyfd, "gotta jump %d lines | height of the command : %d\n", d, d - n);
	if ((int)ft_lstlen(e->line) > e->li * e->co)
	{
		ft_fprintf(e->ttyfd, "command line way too big\n", d);
		return (-1);
	}
	while (n++ < d)
	{
		write(1, "\n", 1);
		if (n > e->li)
		{
			e->curs.sy--;
			e->curs.y--;
		}
	}
	tputs(tgoto(tgetstr("cm", 0), e->curs.sx +
				ft_strlen(e->prmpt) - 1, e->curs.sy - 1), 1, myput);
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
			ft_printf("{red}%c{no}", in->c);
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
	i = e->curs.x - ft_strlen(e->prmpt) - 1 +
		(e->curs.y - e->curs.sy) * e->co;
	ft_fprintf(e->ttyfd, "function ins char {{ %c }} at %i\n",
			*e->buff, i);
	ft_fprintf(e->ttyfd, "END x %d y %d\n",
			((int)ft_strlen(e->prmpt) + e->curs.sx + e->ln)
			% e->co, e->curs.sy + e->ln / e->co);
	if (!(new = ft_lstnew(e->buff, sizeof(t_input))))
		return (1);
	//tputs(tgoto(tgetstr("cm", 0), e->curs.sx +
				//ft_strlen(e->prmpt) - 1, e->curs.sy - 1), 1, myput);
	ft_lstaddat(&e->line, new, i);
	e->ln++;
//	get_eol(e, e->line);
	//putline(e, e->line);
	//tputs(tgetstr("cd", 0), 1, myput);
	//tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	if (!(i = refresh_line(e, e->line)))
		curs_right(e);
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } START @ { %d : %d }\n",
			e->curs.x, e->curs.y, e->curs.sx, e->curs.sy);
	e->beg_sel = -2;
	return (i);
}
