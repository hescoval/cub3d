/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:42:42 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:42:44 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	ans;
	int	negative;

	ans = 0;
	negative = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			negative = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		ans = ans * 10 + (*nptr++ - '0');
	}
	return (ans * negative);
}
