/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:43:59 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:44:00 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*aux1;
	const unsigned char	*aux2;
	size_t				i;
	int					ans;

	aux1 = s1;
	aux2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (aux1[i] == aux2[i] && i < n - 1)
		i++;
	ans = aux1[i] - aux2[i];
	if (ans > 0)
		return (1);
	else if (ans < 0)
		return (-1);
	else
		return (0);
}
