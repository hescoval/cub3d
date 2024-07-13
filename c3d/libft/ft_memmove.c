/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:44:06 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:44:07 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*aux_dest;
	unsigned char		*aux_src;
	size_t				i;

	aux_dest = (unsigned char *) dest;
	aux_src = (unsigned char *) src;
	i = 1;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else if (dest > src)
	{
		while (i <= n)
		{
			aux_dest[n - i] = aux_src[n - i];
			i++;
		}
	}
	return (dest);
}
