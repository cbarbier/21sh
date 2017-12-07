/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/07 13:52:34 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				select_up(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function select_up\n");
	return (0);
}

int				select_down(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function select_down\n");
	return (0);
}

int				select_right(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function select right\n");
	return (0);
}

int				select_left(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function select left\n");
	return (0);
}
