/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/27 21:42:25 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int		putline(t_21sh *e, t_list *l, int n)
{
	int			i;
	t_list		*tmp;

	tmp = l;
	while (tmp)
	{
		ft_fprintf(e->ttyfd, "%c ", *((char *)tmp->content));
		tmp = tmp->next;
	}
	ft_fprintf(e->ttyfd, "\nputline n= %i\n", n);
	i = ft_strlen(e->prmpt) + n;
	while (n--)
		l = l->next;
	while (l)
	{
		ft_fprintf(e->ttyfd, "loop putline %i %% %d\n", i, e->co);
		if (i % e->co == 0)
		{
			ft_fprintf(e->ttyfd, "SAFQDGTHETYRJYJREJYREYJRYJREYJEJ\n");
			if (e->curs.sy + i / e->co == e->li)
				e->curs.sy--;
			//if (!(e->curs.x == e->co && e->curs.y == e->li))
			//tputs(tgetstr("do", 0), 1, myput);
			//tputs(tgetstr("cr", 0), 1, myput);
		}
		write(1, (char *)(l->content), 1);
		l = l->next;
		i++;
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

static int		will_scroll(t_21sh *e, int nbl)
{
	ft_fprintf(e->ttyfd, "nbl = %d  sy %d ln %d co %d\n", nbl, e->curs.sy, e->ln, e->co);
	if (e->ln && e->curs.sy + nbl == e->li
	&& (e->ln + ft_strlen(e->prmpt)) % e->co == 0)
		return (1);
	return (0);
}

int				ins_char(t_21sh *e)
{
	int			i;
	int			l;
	int			scrll;
	t_list		*new;

	l = e->curs.y - e->curs.sy;
	i = e->curs.x - ft_strlen(e->prmpt) - 1 + l * e->co;
	ft_fprintf(e->ttyfd, "function ins char {{ %c }} at %i\n", *e->buff, i);
	scrll = will_scroll(e, l);
	if (!(new = ft_lstnew(e->buff, sizeof(char))))
		return (1);
	tputs(tgetstr("cd", 0), 1, myput);
	tputs(tgetstr("sc", 0), 1, myput);
	ft_lstaddat(&e->line, new, i);
	putline(e, e->line, i);
	tputs(tgetstr("rc", 0), 1, myput);
	ft_fprintf(e->ttyfd, "wiil it scroll ?? %d\n", scrll);
	curs_right(e);
	if (l && scrll)
	{
		tputs(tgetstr("up", 0), 1, myput);
		e->curs.y--;
	}
	e->ln++;
	return (0);
}
