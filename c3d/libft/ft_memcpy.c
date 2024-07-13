/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:44:01 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:44:02 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*aux_src;
	unsigned char		*aux_dest;
	size_t				i;

	i = 0;
	aux_src = (unsigned char *) src;
	aux_dest = dest;
	if (!dest && !src)
		return (dest);
	while (i++ < n)
		*aux_dest++ = *aux_src++;
	return (dest);
}
