/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/21 17:43:34 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				del_char(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function del char\n");
	tputs(tgetstr("dm", 0), 1, myput);
	tputs(tgetstr("dc", 0), 1, myput);
	tputs(tgetstr("ed", 0), 1, myput);
	return (0);
}
