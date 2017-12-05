/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/05 17:31:21 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				refresh_line(t_21sh *e, t_list *l)
{
	e->ln = ft_lstlen(e->line);
	ft_fprintf(e->ttyfd, "selecting DBUG beg=%d & end=%d\n",
			e->beg_sel, e->end_sel);
	tputs(tgoto(tgetstr("cm", 0), e->curs.sx +
				ft_strlen(e->prmpt) - 1, e->curs.sy - 1), 1, myput);
	if (get_eol(e) == -1)
		return (-1);
	tputs(tgetstr("cd", 0), 1, myput);
	putline(e, l);
	tputs(tgoto(tgetstr("cm", 0), e->curs.x - 1, e->curs.y - 1), 1, myput);
	return (0);
}

int				select_up(t_21sh *e)
{
	int				save_beg;

	if (!e->ln || e->curs.y == e->curs.sy)
	{
		ft_fprintf(e->ttyfd, "can-t up  the sleection\n");
		return (0);
	}
	else
	{
		if (e->beg_sel == -2)
			e->beg_sel = e->curs.x - (int)ft_strlen(e->prmpt) - 1 +
				(e->curs.y - e->curs.sy) * e->co;
		save_beg = e->beg_sel;
		go_last_line(e);
		e->beg_sel = save_beg;
		e->end_sel = e->curs.x - (int)ft_strlen(e->prmpt) - 1 +
			(e->curs.y - e->curs.sy) * e->co;
	}
	refresh_line(e, e->line);
	ft_fprintf(e->ttyfd, "function select_up\n");
	return (0);
}

int				select_down(t_21sh *e)
{
	int				save_beg;

	if (!e->ln || e->curs.y == e->li)
	{
		ft_fprintf(e->ttyfd, "can-t down  the sleection\n");
		return (0);
	}
	else
	{
		if (e->beg_sel == -2)
			e->beg_sel = e->curs.x - (int)ft_strlen(e->prmpt) - 1 +
				(e->curs.y - e->curs.sy) * e->co;
		save_beg = e->beg_sel;
		go_next_line(e);
		e->beg_sel = save_beg;
		e->end_sel = e->curs.x - (int)ft_strlen(e->prmpt) - 1 +
			(e->curs.y - e->curs.sy) * e->co;
	}
	refresh_line(e, e->line);
	ft_fprintf(e->ttyfd, "function select_down\n");
	return (0);
}

int				select_right(t_21sh *e)
{
	int				save_beg;

	if (!e->ln || (e->curs.y == e->li && e->curs.x == e->co))
	{
		ft_fprintf(e->ttyfd, "can-t right  the sleection\n");
		return (0);
	}
	else
	{
		if (e->beg_sel == -2)
			e->beg_sel = e->curs.x - (int)ft_strlen(e->prmpt) - 1 +
				(e->curs.y - e->curs.sy) * e->co;
		save_beg = e->beg_sel;
		curs_right(e);
		e->beg_sel = save_beg;
		e->end_sel = e->curs.x - (int)ft_strlen(e->prmpt) - 1 +
			(e->curs.y - e->curs.sy) * e->co;
	}
	refresh_line(e, e->line);
	ft_fprintf(e->ttyfd, "function select_right\n");
	return (0);
}

int				select_left(t_21sh *e)
{
	int				save_beg;

	if (!e->ln || (e->curs.y == e->curs.sy
				&& e->curs.x == (int)ft_strlen(e->prmpt) + 1))
	{
		ft_fprintf(e->ttyfd, "can-t left  the sleection e->ln = %d\n",
				e->ln);
		if (!e->ln)
			return (0);
	}
	else
	{
		if (e->beg_sel == -2)
			e->beg_sel = e->curs.x - (int)ft_strlen(e->prmpt) - 1 +
				(e->curs.y - e->curs.sy) * e->co;
		save_beg = e->beg_sel;
		curs_left(e);
		e->beg_sel = save_beg;
		e->end_sel = e->curs.x - (int)ft_strlen(e->prmpt) - 1 +
			(e->curs.y - e->curs.sy) * e->co;
	}
	ft_fprintf(e->ttyfd, "function select_left\n");
	return (refresh_line(e, e->line));
}
