/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/29 15:04:07 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

int			key_is_del(char *buff)
{
	char const *ret = "\x7f\0\0\0\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_char(char *buff)
{
	char const *ret = "\0\0\0\0\0\0\0\0\0";

	if (!ft_memcmp(ret, buff + 1, MAX_KEY_STRING_LENGTH)
	&& buff[0] >= 32 && buff[0] < 127)
		return (TRUE);
	return (FALSE);
}

int			key_is_alt_x(char *buff)
{
	char const *ret = "\x1b\x78\0\0\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_alt_c(char *buff)
{
	char const *ret = "\x1b\x63\0\0\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_alt_v(char *buff)
{
	char const *ret = "\x1b\x76\0\0\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}
