/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_lien.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:28:57 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/07 16:12:15 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int						refresh_cursor(t_21sh *e)
{
	t_cursor		*c;

	ft_fprintf(e->ttyfd, "function refresh cursor\n");
	c = &e->c;
	c->x = c->sx + c->p % e->t.co;
	c->y = c->sy + c->p / e->t.co;
	tputs(tgoto(tgetstr("cm", 0), e->c.x - 1, e->c.y - 1), 1, myput);
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } POS [%d] START @ { %d : %d }\n", e->c.x, e->c.y, e->c.p, e->c.sx, e->c.sy);
	return (0);
}

static int				put_line(t_21sh *e, char *l)
{
	int			ln;
	int			step;
	int			up;

	ft_fprintf(e->ttyfd, "function put line\n");
	l = e->in.txt;
	ln = ft_strlen(l);
	up = e->c.sy;
	step = (ln > e->t.co ? e->t.co - e->c.sx : ln);
	while (ln)
	{
		ft_fprintf(e->ttyfd, "ln %d  up %d step %d l: %s\n", ln, up, step, l);
		if (up++ > e->t.li)
			e->c.sy--;
		write(1, l, step);
		l += step;
		ln -= step;
		step = (e->t.co < ln ? e->t.co : ln);
	}
	return (0);
}

int						refresh_line(t_21sh *e)
{
	tputs(tgoto(tgetstr("cm", 0), e->c.sx - 1, e->c.sy - 1), 1, myput);
	tputs(tgetstr("cd", 0), 1, myput);
	put_line(e, e->in.txt);
	refresh_cursor(e);
	return (0);
}
