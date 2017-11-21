/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 11:03:54 by cbarbier          #+#    #+#             */
/*   Updated: 2017/11/14 17:13:07 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int			key_is_home(char *buff)
{
	static char		*ret = 0;

	if (!ret)
		ret = tgetstr("kh", 0);
	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_left(char *buff)
{
	static char		*ret = 0;

	if (!ret)
		ret = tgetstr("kl", 0);
	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_right(char *buff)
{
	static char		*ret = 0;

	if (!ret)
		ret = tgetstr("kr", 0);
	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_up(char *buff)
{
	static char		*ret = 0;

	if (!ret)
		ret = tgetstr("ku", 0);
	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}

int			key_is_down(char *buff)
{
	static char		*ret = 0;

	if (!ret)
		ret = tgetstr("kd", 0);
	if (!ft_memcmp(ret, buff, MAX_KEY_STRING_LENGTH))
		return (TRUE);
	return (FALSE);
}
