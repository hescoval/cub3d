/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:44:19 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:44:20 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_withminus(t_arg *arg, t_string *string, char *content);
static void	ft_withoutminus(t_arg *arg, t_string *string, char *content);

void	ft_print_s(t_arg *arg, t_string *string, va_list lst)
{
	char	*content;
	int		contentlen;

	content = va_arg(lst, char *);
	if (!content)
	{
		if (arg->dot && arg->precision < 6)
			content = "";
		else
			content = "(null)";
	}
	contentlen = ft_strlen(content);
	if (arg->precision < 0 || arg->precision > contentlen)
		arg->precision = contentlen;
	if (arg->minus)
		ft_withminus(arg, string, content);
	else
		ft_withoutminus(arg, string, content);
}

static void	ft_withminus(t_arg *arg, t_string *string, char *content)
{
	while (arg->precision > 0 && *content)
	{
		ft_printchar(*content++, string);
		arg->width--;
		arg->precision--;
	}
	while (arg->width > 0)
	{
		ft_printchar(' ', string);
		arg->width--;
	}
}

static void	ft_withoutminus(t_arg *arg, t_string *string, char *content)
{
	while (arg->width > arg->precision)
	{
		ft_printchar(' ', string);
		arg->width--;
	}
	while (arg->precision > 0 && *content)
	{
		ft_printchar(*content++, string);
		arg->precision--;
	}
}
