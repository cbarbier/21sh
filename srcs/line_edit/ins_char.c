/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/01 00:04:43 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int		get_eol(t_21sh *e, t_list *tmp)
{
	e->eol.x = e->curs.sx + ft_strlen(e->prmpt);
	e->eol.y = e->curs.sy;
	while (tmp)
	{
		ft_fprintf(e->ttyfd, "%c ", ((t_input *)tmp->content)->c);
		if (e->eol.y == e->li && e->eol.x == e->co)
		{
			ft_fprintf(e->ttyfd, "ENDoF TERM\n");
			e->curs.sy--;
			e->curs.y--;
		}
		e->eol.x = e->eol.x == e->co ? 1 : e->eol.x + 1;
		if (e->eol.x == 1 && e->eol.y < e->li)
			e->eol.y++; tmp = tmp->next;
	}
	ft_fprintf(e->ttyfd, "EOL {%d : %d}\n", e->eol.x, e->eol.y);
	return (0);
}

int				putline(t_21sh *e, t_list *l)
{
	t_input			*in;
	int				i;

	(void)e;
	i = 0;
	while (l)
	{
		in = (t_input *)l->content;
		if (e->beg_sel != -2 && i >= MIN(e->beg_sel, e->end_sel) && i <= MAX(e->beg_sel, e->end_sel))
			ft_printf("{red}%c{no}", in->c);
		else
			write(1, &in->c, 1);
		i++;
		l = l->next;
	}
	write(1, " ", 1);
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
	in.sel = 0;
	i = e->curs.x - ft_strlen(e->prmpt) - 1 +  (e->curs.y - e->curs.sy) * e->co;
	ft_fprintf(e->ttyfd, "function ins char {{ %c }} at %i\n", *e->buff, i);
	ft_fprintf(e->ttyfd, "END x %d y %d\n", ((int)ft_strlen(e->prmpt) + e->curs.sx + e->ln) % e->co, e->curs.sy + e->ln / e->co);
	if (!(new = ft_lstnew(e->buff, sizeof(t_input))))
		return (1);
	tputs(tgoto(tgetstr("cm", 0), e->curs.sx + ft_strlen(e->prmpt) - 1, e->curs.sy - 1), 1, myput);
	ft_lstaddat(&e->line, new, i);
	get_eol(e, e->line);
	putline(e, e->line);
	tputs(tgetstr("cd", 0), 1, myput);
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	curs_right(e);
	e->ln++;
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } START @ { %d : %d }\n", e->curs.x, e->curs.y, e->curs.sx, e->curs.sy);
	e->beg_sel = -2;
	return (0);
}
