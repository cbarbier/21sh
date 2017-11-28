/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/28 15:35:31 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int		get_eol(t_21sh *e, t_list *tmp)
{
	e->eol.x = e->curs.sx + ft_strlen(e->prmpt);
	e->eol.y = e->curs.sy;
	while (tmp)
	{
		ft_fprintf(e->ttyfd, "%c ", *((char *)tmp->content));
		if (e->eol.y == e->li && e->eol.x == e->co)
		{
			ft_fprintf(e->ttyfd, "ENDoF TERM\n");
			e->curs.sy--;
			e->curs.y--;
		}
		e->eol.x = e->eol.x == e->co ? 1 : e->eol.x + 1;
		if (e->eol.x == 1 && e->eol.y < e->li)
			e->eol.y++;
		tmp = tmp->next;
	}
	ft_fprintf(e->ttyfd, "EOL {%d : %d}\n", e->eol.x, e->eol.y);
	return (0);
}

static int		putline(t_21sh *e, t_list *l)
{
	(void)e;
	while (l)
	{
		write(1, (char *)(l->content), 1);
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
	int			l;
	t_list		*new;

	l = e->curs.y - e->curs.sy;
	i = e->curs.x - ft_strlen(e->prmpt) - 1 + l * e->co;
	ft_fprintf(e->ttyfd, "function ins char {{ %c }} at %i\n", *e->buff, i);
	ft_fprintf(e->ttyfd, "END x %d y %d\n", ((int)ft_strlen(e->prmpt) + e->curs.sx + e->ln) % e->co, e->curs.sy + e->ln / e->co);
	if (!(new = ft_lstnew(e->buff, sizeof(char))))
		return (1);
	tputs(tgoto(tgetstr("cm", 0), e->curs.sx + ft_strlen(e->prmpt) - 1, e->curs.sy - 1), 1, myput);
	ft_lstaddat(&e->line, new, i);
	get_eol(e, e->line);
	putline(e, e->line);
	tputs(tgetstr("cd", 0), 1, myput);
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	curs_right(e);
	e->ln++;
	return (0);
}
