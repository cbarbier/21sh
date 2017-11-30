/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/01 00:17:37 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
/*
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
*/

int				ft_lstdelsub(t_21sh *e, t_list **al, void (*del)(void*, size_t), int a, int b)
{
	t_list			*l;
	t_list			*tmp;
	t_list			*join;
	int				i;

	if (!(l = *al) || b - a == 0)
		return (1);
	if (e->beg_sel > e->end_sel)
	{
		a++;
		b++;
	}
	i = 0;
	while (l->next && ++i < a)
		l = l->next;
	join = (!a ? 0 : l);
	ft_fprintf(e->ttyfd, "end of first part char :  %c\n" , ((t_input *)(l->content))->c );
	l = l->next;
	while (l && i < b)
	{
		tmp = l->next;
		ft_fprintf(e->ttyfd, "char to be deleted :  %c\n" , ((t_input *)(l->content))->c );
		ft_lstdelone(&l, del);
		l = tmp;
		i++;
	}
	ft_fprintf(e->ttyfd, "end of del part char :  %c\n" , (l ? ((t_input *)(l->content))->c : '0'));
	if (join)
		join->next = l;
	else
		*al = l;
	return (0);
}

int				do_cut(t_21sh *e)
{
	int				n;

	if (e->beg_sel == -2)
	{
		ft_fprintf(e->ttyfd, "nothing to cut\n");
		return (0);
	}
	ft_fprintf(e->ttyfd, "LAST LEN  %d\n", e->ln);
	n = MIN(e->beg_sel, e->end_sel);
	e->curs.x = (n + (int)ft_strlen(e->prmpt) + 1) % e->co;
	e->curs.y = e->curs.sy + (n + (int)ft_strlen(e->prmpt)) / e->co;
	ft_fprintf(e->ttyfd, "function do_cut reset cursor  %d\n", n);
	ft_fprintf(e->ttyfd, "deleting from  %d  to  %d\n", n, MAX(e->beg_sel, e->end_sel));
	if (!ft_lstdelsub(e, &e->line, del_line, n, MAX(e->beg_sel, e->end_sel)))
		e->ln -= (MAX(e->beg_sel, e->end_sel) - n);
	ft_fprintf(e->ttyfd, "NEW LEN  %d\n", e->ln);
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	e->beg_sel = -2;
	refresh_line(e, e->line);
	return (0);
}
