/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:44:10 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:44:11 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_c(t_arg *arg, t_string *string, va_list lst)
{
	char	c;

	c = va_arg(lst, int);
	if (arg->minus)
	{
		ft_printchar(c, string);
		while (arg->width > 1)
		{
			ft_printchar(' ', string);
			arg->width--;
		}
	}
	else
	{
		while (arg->width > 1)
		{
			ft_printchar(' ', string);
			arg->width--;
		}
		ft_printchar(c, string);
	}
}
