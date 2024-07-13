/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:43:47 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:43:49 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	void	*cont;

	if (!lst || !f || !del)
		return (NULL);
	cont = f(lst->content);
	newlst = ft_lstnew(cont);
	if (!newlst)
	{
		del(cont);
		return (NULL);
	}
	return (newlst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*newlst;
	void	*cont;

	map = ft_map(lst, f, del);
	if (!map)
		return (NULL);
	newlst = map;
	lst = lst->next;
	while (lst)
	{
		cont = f(lst->content);
		newlst->next = ft_lstnew(cont);
		if (!newlst->next)
		{
			del(cont);
			ft_lstclear(&map, del);
			return (NULL);
		}
		newlst = newlst->next;
		lst = lst->next;
	}
	newlst->next = NULL;
	return (map);
}
