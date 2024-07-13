/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:45:24 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/13 00:09:48 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	while (slen > 0)
	{
		if (s[slen] == (char) c)
			return ((char *)&s[slen]);
		slen--;
	}
	if (s[slen] == (char) c)
		return ((char *)&s[slen]);
	return (0);
}
