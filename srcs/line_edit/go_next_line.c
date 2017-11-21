/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/21 17:46:19 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				go_next_line(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function go next line\n");
	tputs(tgoto(tgetstr("DO", 0), 1, 0), 1, myput); 
	return (0);
}
