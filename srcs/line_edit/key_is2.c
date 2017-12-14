/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/28 18:23:45 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

int			key_is_end(char *buff)
{
	char const		*ret = "\x1b\x5b\x46\0\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_left(char *buff)
{
	static char		*ret = "\x1b\x5b\x44\0\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_right(char *buff)
{
	static char		*ret = "\x1b\x5b\x43\0\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_up(char *buff)
{
	static char		*ret = "\x1b\x5b\x41\0\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_down(char *buff)
{
	static char		*ret = "\x1b\x5b\x42\0\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}
