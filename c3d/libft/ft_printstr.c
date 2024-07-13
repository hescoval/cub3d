/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:44:36 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:44:37 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstr(const char *s, t_string *string)
{
	while (*s)
		ft_printchar(*s++, string);
}

void	ft_printstr_ltda(const char *s, t_string *string)
{
	while (*s && *s != '%')
		ft_printchar(*s++, string);
}
