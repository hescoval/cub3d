/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:45:02 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:45:03 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*newstr;

	slen = ft_strlen(s) + 1;
	newstr = ft_calloc(slen, 1);
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s, slen);
	return (newstr);
}
