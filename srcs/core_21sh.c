/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_21sh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:33:24 by cbarbier          #+#    #+#             */
/*   Updated: 2018/01/09 19:43:07 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

int				put_buff(t_21sh *e, char *buff)
{
	ft_fprintf(e->ttyfd, "DEBUG[%x][%x][%x][%x][%x][%x][%x][%x][%x]\n",
			(int)buff[0], (int)buff[1], (int)buff[2],
			(int)buff[3], (int)buff[4], (int)buff[5],
			(int)buff[6], (int)buff[7], (int)buff[8]);
	return (0);
}

int				core_21sh(t_21sh *e)
{
	signal(SIGWINCH, resize_handler);
	while (e->run)
	{
		ft_bzero(e->buff, MAX_KEY_STRING_LENGTH + 1);
		read(0, e->buff, MAX_KEY_STRING_LENGTH);
		put_buff(e, e->buff);
		key_apply_func(e);
	}
	return (0);
}
