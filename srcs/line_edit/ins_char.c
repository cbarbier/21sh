/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/07 16:14:25 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				ins_char(t_21sh *e)
{
	ft_fprintf(e->ttyfd, "function ins char {{ %c }}\n", *e->buff);
	ft_strncat(e->in.txt, e->buff, 1);
	e->c.p++;
	e->in.ln++;
	ft_fprintf(e->ttyfd, "CURSOR { %d : %d } POS [%d] START @ { %d : %d }\n", e->c.x, e->c.y, e->c.p, e->c.sx, e->c.sy);
	return (0);
}
