/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:42:50 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:42:51 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;
	size_t			b_size;
	size_t			i;

	b_size = nmemb * size;
	i = 0;
	temp = malloc(b_size);
	if (temp == NULL)
		return (NULL);
	while (i < b_size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
