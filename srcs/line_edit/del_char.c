/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/01 04:38:06 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static	int		to_del(void *ct, void *d)
{
	t_cursor		*data;

	(void)ct;
	data = (t_cursor *)d;
	if (data->x++ == data->y)
		return (1);
	return (0);
}

static int		put_eol(t_21sh *e, t_list *l, int n)
{
	t_input		*in;
	int			i;

	i = 1;
	(void)e;
	while (l && --n)
		l = l->next;
	while (l)
	{
		in = (t_input *)l->content;
		write(1, &in->c, 1);
		l = l->next;
	}
	return (0);
}

int				del_char(t_21sh *e)
{
	t_cursor		data;

	if (e->curs.y == e->curs.sy
	&& e->curs.x == e->curs.sx + (int)ft_strlen(e->prmpt))
	{
		ft_fprintf(e->ttyfd, "start position => no deletion\n");
		return (0);
	}
	data.x = 1;
	data.y = e->curs.x - ft_strlen(e->prmpt) - 1 +
		(e->curs.y - e->curs.sy) * e->co;
	ft_lstfilter(&e->line, del_line, to_del, (void *)&data);
	ft_fprintf(e->ttyfd, "function del char\n");
	curs_left(e);
	tputs(tgetstr("sc", 0), 1, myput);
	tputs(tgetstr("cd", 0), 1, myput);
	put_eol(e, e->line, data.y);
	tputs(tgetstr("rc", 0), 1, myput);
	e->ln--;
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } START @ { %d : %d }\n",
			e->curs.x, e->curs.y, e->curs.sx, e->curs.sy);
	return (0);
}
