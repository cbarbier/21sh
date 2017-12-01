/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 09:33:24 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/01 17:33:21 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int	put_tc(int ttyfd, char *cap)
{
	char buff[7];

	ft_bzero(buff, 7);
	ft_strcat(buff, tgetstr(cap, 0));
	ft_fprintf(ttyfd, "capibility \"%s\" [%x][%x][%x][%x][%x][%x]\n", cap,
			(int)buff[0], (int)buff[1], (int)buff[2], (int)buff[3],
			(int)buff[4], (int)buff[5]);
	return (0);
}

int			myput(int c)
{
	write(1, &c, 1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_21sh				e;

	if (init_21sh(&e, argc, argv))
		return (exit_21sh(&e));
	core_21sh(&e);
	return (0);
}
