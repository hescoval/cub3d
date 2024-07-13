/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:43:27 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:43:28 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itlen(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len = 2;
		n = -n;
	}
	else
		len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ittoed;
	long	num;
	size_t	len;
	size_t	i;

	i = 2;
	num = n;
	len = ft_itlen(num) + 1;
	ittoed = ft_calloc(len, 1);
	if (!ittoed)
		return (NULL);
	if (num < 0)
	{
		ittoed[0] = '-';
		num = -num;
	}
	while (num >= 10)
	{
		ittoed[len - i] = num % 10 + '0';
		num /= 10;
		i++;
	}
	ittoed[len - i] = num + '0';
	return (ittoed);
}
