/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:45:44 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/06 11:49:36 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "z1sh.h"

char			*ft_lsttostr(t_list *l)
{
	int				i;
	int				n;
	char			*str;
	t_input			*in;

	n = ft_lstlen(l);
	if (!n || !(str = ft_strnew(n)))
		return (0);
	i = 0;
	while (l)
	{
		in = (t_input *)l->content;
		str[i++] = in->c;
		l = l->next;
	}
	return (str);
}
