/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/21 16:45:48 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				go_home(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function go home\n");
	return (0);
}
