/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:43:55 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:43:56 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*aux;

	aux = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (aux[i] == (unsigned char) c)
			return (&aux[i]);
		i++;
	}
	return (0);
}
