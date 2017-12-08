/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_lien.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:28:57 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/08 15:49:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int						refresh_cursor(t_21sh *e)
{
	t_cursor		*c;

	ft_fprintf(e->ttyfd, "function refresh cursor\n");
	c = &e->c;
	c->x = (c->sx + c->p) % e->t.co;
	c->y = c->sy + (c->sx + c->p) / e->t.co;
	tputs(tgoto(tgetstr("cm", 0), e->c.x, e->c.y), 1, myput);
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } POS [%d] START @ { %d : %d }\n", e->c.x, e->c.y, e->c.p, e->c.sx, e->c.sy);
	return (0);
}

static int				put_line(t_21sh *e, char *l)
{

	ft_fprintf(e->ttyfd, "function put line\n");
	write(1, l, e->in.ln);
	return (0);
}

int						refresh_line(t_21sh *e)
{
	int				delta;
	int				i;

	tputs(tgoto(tgetstr("cm", 0), e->c.sx, e->c.sy), 1, myput);
	tputs(tgetstr("cd", 0), 1, myput);
	delta = (e->c.sx + e->in.ln) / e->t.co;
	ft_fprintf(e->ttyfd, "delta : %d\n", delta);
	if (delta)
	{
		i = 0;
		while (i++ < delta)
			write(1, "\n", 1);
		if (e->c.sy + delta >= e->t.li)
			e->c.sy -= (e->c.sy + delta - e->t.li);
	}
	put_line(e, e->in.txt);
	refresh_cursor(e);
	return (0);
}
