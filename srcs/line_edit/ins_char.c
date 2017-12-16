/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/14 16:10:48 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

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
	t_list		*new;
	t_input		in;

	ft_bzero(&in, sizeof(t_input));
	in.c = (*e->buff == 'q' ? '\n' : *e->buff);
	ft_fprintf(e->ttyfd, "function ins char {{ %c }} at %i\n", *e->buff, e->n);
	if (!(new = ft_lstnew(&in, sizeof(t_input))))
		return (1);
	ft_lstaddat(&e->line, new, e->n);
	e->ln++;
	e->beg_sel = -2;
	curs_right(e);
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } START @ { %d : %d } n %d\n",
			e->curs.x, e->curs.y, e->curs.sx, e->curs.sy, e->n);
	return (0);
}
