/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:44:41 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:44:41 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_ptlen(unsigned long n)
{
	size_t	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_ptoa(unsigned long n)
{
	char	*xttoed;
	char	*hexa;
	size_t	len;
	size_t	i;

	hexa = "0123456789abcdef";
	i = 2;
	len = ft_ptlen(n) + 1;
	xttoed = ft_calloc(len, sizeof(char));
	if (!xttoed)
		return (NULL);
	while (n >= 16)
	{
		xttoed[len - i] = hexa[n % 16];
		n /= 16;
		i++;
	}
	xttoed[len - i] = hexa[n];
	return (xttoed);
}
