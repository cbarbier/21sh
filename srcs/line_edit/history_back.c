/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:16:42 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/30 13:44:04 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				history_back(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function history back\n");
	e->beg_sel = -1;
	return (0);
}