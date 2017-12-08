/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_paste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/08 18:20:35 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				ft_lstjoinat(t_list **al, t_list *ll, int n)
{
	t_list			*l;
	t_list			*tmp;
	int				i;

	if (!(l = *al) && !ll)
		return (1);
	if (!l || !n)
	{
		*al = ll;
		ft_lstpushback(al, l);
		return (0);
	}
	i = 0;
	while (l->next && ++i < n)
		l = l->next;
	tmp = l->next;
	l->next = ll;
	ft_lstpushback(&l, tmp);
	return (0);
}

int				do_paste(t_21sh *e)
{
	int			i;
	int			n;

	i = e->curs.x - e->curs.sx + (e->curs.y - e->curs.sy) * e->co;
	ft_fprintf(e->ttyfd, "function do_paste at index %i\n", i);
	e->beg_sel = -2;
	if (!ft_lstjoinat(&e->line, ft_lstcpy(e->save, sizeof(t_input *)), i))
		e->ln += ft_lstlen(e->save);
	n = ft_lstlen(e->save);
	if ((i = refresh_line(e, e->line)))
		return (i);
	while (n--)
		curs_right(e);
	return (0);
}
