/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/21 18:42:08 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				ins_char(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function ins char {{ %c }}\n", *e->buff);
	tputs(tgetstr("ic", 0), 1, myput); 
	myput(e->buff[0]);
	tputs(tgetstr("ip", 0), 1, myput); 
	return (0);
}
