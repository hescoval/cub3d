/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:50:52 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/13 20:54:29 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace(char *str, char old, char new)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str == old)
			*str = new;
		str++;
	}
}
