/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/10/20 11:43:17 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int			key_is_crtl_d(char *buff)
{
	char const *ret = "\x4\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_crtl_r(char *buff)
{
	char const *ret = "\x12\0\0\0\0\0";

	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}


