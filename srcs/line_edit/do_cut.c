/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/05 17:27:17 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void		store_save(t_21sh *e, t_list *l, int a, int b)
{
	int			i;
	t_list		*elm;
	t_input		*in;

	i = 0;
	if (e->beg_sel > e->end_sel)
	{
		a++;
		b++;
	}
	ft_fprintf(e->ttyfd, "a=%d &&&& b=%d\n", a, b);
	while (l && ++i <= a)
		l = l->next;
	while (l && i++ <= b)
	{
		in = (t_input *)(l->content);
		if (!(elm = ft_lstnew(l->content, sizeof(t_input))))
			return ;
		in->del = 1;
		elm->next = 0;
		ft_lstpushback(&e->save, elm);
		l = l->next;
	}
}

static int		del_cut(void *ct, void *d)
{
	t_input		*in;

	(void)d;
	in = (t_input *)(ct);
	return (in->del);
}

int				do_cut(t_21sh *e)
{
	int				n;
	t_list			*l;

	if (e->beg_sel == -2)
	{
		ft_fprintf(e->ttyfd, "nothing to cut\n");
		return (0);
	}
	ft_lstdel(&e->save, del_line);
	ft_fprintf(e->ttyfd, "LAST LEN  %d\n", e->ln);
	n = MIN(e->beg_sel, e->end_sel);
	e->curs.x = (n + (int)ft_strlen(e->prmpt) + 1) % e->co;
	e->curs.y = e->curs.sy + (n + (int)ft_strlen(e->prmpt)) / e->co;
	ft_fprintf(e->ttyfd, "function do_cut reset cursor  %d\n", n);
	ft_fprintf(e->ttyfd, "deleting from  %d  to  %d\n",
			n, MAX(e->beg_sel, e->end_sel));
	store_save(e, e->line, n, MAX(e->beg_sel, e->end_sel));
	ft_lstfilter(&e->line, del_line, del_cut, 0);
	e->ln = ft_lstlen(e->line);
	ft_fprintf(e->ttyfd, "save list :\n");
	l = e->save;
	ft_fprintf(e->ttyfd, "NEW LEN  %d\n", e->ln);
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	e->beg_sel = -2;
	return (refresh_line(e, e->line));
}
