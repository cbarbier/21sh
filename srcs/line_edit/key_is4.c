/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/29 11:04:59 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int			key_is_alt_left(char *buff)
{
	static char		*ret = "\x1b\x1b\x5b\x44\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_alt_right(char *buff)
{
	static char		*ret = "\x1b\x1b\x5b\x43\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_alt_up(char *buff)
{
	static char		*ret = "\x1b\x1b\x5b\x41\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_alt_down(char *buff)
{
	static char		*ret = "\x1b\x1b\x5b\x42\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}
