/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/12 16:14:04 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

int				select_mode(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function select_mode\n");
	if (!e->ln || e->beg_sel != -2)
	{
		e->beg_sel = -2;
		return (0);
	}
	e->beg_sel = e->n;
	e->end_sel = e->beg_sel;
	return (0);
}

int				select_up(t_21sh *e)
{
	int			save_beg;

	ft_fprintf(e->ttyfd, "function select_up\n");
	if (!e->ln || e->curs.y == e->curs.sy)
	{
		ft_fprintf(e->ttyfd, "can-t up  the sleection\n");
		return (0);
	}
	else
	{
		save_beg = e->beg_sel;
		go_last_line(e);
		e->beg_sel = save_beg;
		e->end_sel = e->n;
		return (0);
	}
	return (0);
}

int				select_down(t_21sh *e)
{
	int			save_beg;

	ft_fprintf(e->ttyfd, "function select_down\n");
	if (!e->ln || e->curs.y == e->li)
	{
		ft_fprintf(e->ttyfd, "can-t down  the sleection\n");
		return (0);
	}
	else
	{
		save_beg = e->beg_sel;
		go_next_line(e);
		e->beg_sel = save_beg;
		e->end_sel = e->n;
		return (0);
	}
	return (0);
}

int				select_right(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function select_right\n");
	if (!e->ln || (e->curs.y == e->li && e->curs.x == e->co))
	{
		ft_fprintf(e->ttyfd, "can-t right  the sleection\n");
		return (0);
	}
	else
		e->end_sel = e->n;
	return (0);
}

int				select_left(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function select_left\n");
	if (!e->ln)
	{
		ft_fprintf(e->ttyfd, "can-t left  the sleection e->ln = %d\n",
				e->ln);
		return (0);
	}
	else
		e->end_sel = e->n;
	return (0);
}
