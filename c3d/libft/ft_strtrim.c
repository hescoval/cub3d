/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:45:27 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:45:28 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		s1_len;

	while (ft_in_set(*s1, set))
		s1++;
	s1_len = ft_strlen(s1);
	while (ft_in_set(s1[s1_len - 1], set))
		s1_len--;
	trim = ft_substr(s1, 0, s1_len);
	return (trim);
}
