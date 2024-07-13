/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:45:07 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:45:08 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = ft_calloc(s1_len + s2_len + 1, 1);
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, s1_len + 1);
	ft_strlcat(joined, s2, s1_len + s2_len + 1);
	return (joined);
}
