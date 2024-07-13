/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:45:22 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:45:23 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (*little == '\0' || !little)
		return ((char *) big);
	while (i < len && big[i])
	{
		if (little_len + i > len)
			return (0);
		if (ft_strncmp(&big[i], little, little_len) == 0)
		{
			return ((char *) &big[i]);
		}
		i++;
	}
	return (0);
}
