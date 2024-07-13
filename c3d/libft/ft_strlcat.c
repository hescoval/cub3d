/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:45:10 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:45:11 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size > 0)
	{
		while (dstlen + i < size - 1 && src[i])
		{
			dst[dstlen + i] = src[i];
			i++;
		}
	}
	dst[dstlen + i] = '\0';
	if (size < dstlen)
		return (srclen + size);
	else
		return (dstlen + srclen);
}
