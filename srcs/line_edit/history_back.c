/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:16:42 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/21 16:46:19 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				history_back(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function history back\n");
	return (0);
}
