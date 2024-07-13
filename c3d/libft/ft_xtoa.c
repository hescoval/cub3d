/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:45:39 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:45:40 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_xtoando(long num, size_t len, size_t i, char *xttoed);

static size_t	ft_xtlen(long n)
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
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_xtoa(unsigned int n)
{
	char	*xttoed;
	long	num;
	size_t	len;
	size_t	i;

	i = 2;
	num = n;
	len = ft_xtlen(num) + 1;
	xttoed = ft_calloc(len, 1);
	if (!xttoed)
		return (NULL);
	ft_xtoando(num, len, i, xttoed);
	return (xttoed);
}

static void	ft_xtoando(long num, size_t len, size_t i, char *xttoed)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (num < 0)
	{
		xttoed[0] = '-';
		num = -num;
	}
	while (num >= 16)
	{
		xttoed[len - i] = hexa[num % 16];
		num /= 16;
		i++;
	}
	xttoed[len - i] = hexa[num];
}
