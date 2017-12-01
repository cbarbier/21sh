/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/01 04:38:45 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_list			*ft_lstsub(t_21sh *e, t_list *l, int a, int b)
{
	int			i;
	t_list		*elm;
	t_list		*sub;

	i = 0;
	sub = 0;
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
		if (!(elm = ft_lstnew(l->content, sizeof(t_input))))
			return (0);
		elm->next = 0;
		ft_lstpushback(&sub, elm);
		l = l->next;
	}
	return (sub);
}

int				do_copy(t_21sh *e)
{
	t_list			*l;

	ft_fprintf(e->ttyfd, "function do_copy\n");
	if (e->beg_sel == -2)
	{
		ft_fprintf(e->ttyfd, "nothing to copy\n");
		return (0);
	}
	ft_fprintf(e->ttyfd, "cleaning the last save\n");
	ft_lstdel(&e->save, del_line);
	ft_fprintf(e->ttyfd, "trying to sub the list line\n");
	if (!(e->save = ft_lstsub(e, e->line, MIN(e->beg_sel, e->end_sel),
					MAX(e->beg_sel, e->end_sel))))
		return (0);
	l = e->save;
	ft_fprintf(e->ttyfd, "e->save : \n");
	while (l)
	{
		ft_fprintf(e->ttyfd, "%c ", ((t_input *)(l->content))->c);
		l = l->next;
	}
	return (0);
}
