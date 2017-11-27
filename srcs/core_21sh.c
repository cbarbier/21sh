/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_21sh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:33:24 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/22 09:42:21 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				put_buff(t_21sh *e, char *buff)
{
	ft_fprintf(e->ttyfd, "DEBUG[%x][%x][%x][%x][%x][%x]\n", (int)buff[0], (int)buff[1], (int)buff[2], (int)buff[3], (int)buff[4], (int)buff[5]);
	return (0);
}

int				core_21sh(t_21sh *e)
{
	while (e->run)
	{
		ft_bzero(e->buff, MAX_KEY_STRING_LENGTH + 1);
		read(0, e->buff, MAX_KEY_STRING_LENGTH);
		put_buff(e, e->buff);
		key_apply_func(e);	
	}
	return (0);
}
