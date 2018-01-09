/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_prmpt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:41:37 by cbarbier          #+#    #+#             */
/*   Updated: 2018/01/09 19:01:46 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

int		print_prmpt(t_21sh *e)
{
	static char		col = '1';

	if (col++ == '7')
		col = '1';
	ft_printf("\033[3%cm%s{no}", col, e->prmpt);
	return (0);
}

int		set_prmpt(t_21sh *e, char *str)
{
	ft_strdel(&e->prmpt);
	if (!(e->prmpt = ft_strdup(str)))
		return (-1);
	return (0);
}
