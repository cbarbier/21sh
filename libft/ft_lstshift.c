/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:04:13 by cbarbier          #+#    #+#             */
/*   Updated: 2017/12/01 02:55:47 by cbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstshift(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;

	if (!alst || !del || !*alst)
		return ;
	lst = (*alst)->next;
	ft_lstdelone(alst, del);
	*alst = lst;
}
