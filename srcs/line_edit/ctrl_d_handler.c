/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_d_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2018/01/09 19:49:50 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

int				ctrl_c_handler(t_21sh *e)
{
	set_prmpt(e, "\n21sh$ ");
	next_loop(e, 0, 0);
	set_prmpt(e, "21sh$ ");
	return (0);
}

int				ctrl_d_handler(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function ctrl d handler\n");
	exit_21sh(e, 1);
	return (0);
}

int				ctrl_u_handler(t_21sh *e)
{
	ft_lstdel(&e->line, del_line);
	e->n = 0;
	return (0);
}
