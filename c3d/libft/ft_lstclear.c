/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:43:38 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:43:39 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextnode;

	if ((lst))
	{
		while ((*lst))
		{
			nextnode = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = nextnode;
		}
	}
}
