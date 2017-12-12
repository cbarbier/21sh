/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/12 18:03:18 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int		lst_next_line(t_21sh *e, t_list *l, int n)
{
	int			i;
	t_input		*cur;
	t_input		*in;

	i = 0;
	while (l && i++ < n)
		l = l->next;
	ft_fprintf(e->ttyfd, "end of curent word i=%d\n", i);
	if (l)
	{
		cur = (t_input *)l->content;
		l = l->next;
	}
	while (l)
	{
		i++;
		in = (t_input *)l->content;
	   	if (in->c == '\n' || (in->y == cur->y + 1 && (in->x == cur->x)))
			break;
		l = l->next;
	}
	return (l ? i : -1);
}

int				go_next_line(t_21sh *e)
{
	int				i;

	ft_fprintf(e->ttyfd, "function go next line\n");
	if ((i = lst_next_line(e, e->line, e->n) == -1))
	{
		ft_fprintf(e->ttyfd, "next line not found\n");
		return (0);
	}
	e->n = i;
	return (0);
}
