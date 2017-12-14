/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_next_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/12 18:04:02 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

int				lst_next_word(t_21sh *e, t_list *l, int n)
{
	int			i;

	i = 0;
	while (l && (i++ < n || !ft_strchr(" \n\t", ((t_input *)l->content)->c)))
		l = l->next;
	if (l)
		l = l->next;
	ft_fprintf(e->ttyfd, "end of curent lien i=%d\n", i);
	while (l && ft_strchr(" \t\n", ((t_input *)l->content)->c) && i++)
		l = l->next;
	return (l ? i : -1);
}

int				go_next_word(t_21sh *e)
{
	int				i;

	ft_fprintf(e->ttyfd, "function  go next line cursor at n=%d\n", e->n);
	if ((i = lst_next_word(e, e->line, e->n)) == -1)
	{
		ft_fprintf(e->ttyfd, "can't find next line\n");
		return (0);
	}
	ft_fprintf(e->ttyfd, "next line indice i=%d\n", i);
	e->n = i;
	if (e->beg_sel != -2)
		e->end_sel = i;
	return (0);
}
