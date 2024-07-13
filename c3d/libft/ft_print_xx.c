/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:44:29 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/10 15:44:29 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_withminus(t_arg *arg, t_string *string, char *content);
static void	ft_withoutminus(t_arg *arg, t_string *string, char *content);
static void	ft_finish(t_arg *arg, t_string *string, char *content);

void	ft_print_xx(t_arg *arg, t_string *string, va_list lst)
{
	unsigned int	num;
	char			*str;

	num = va_arg(lst, unsigned int);
	str = ft_xxtoa(num);
	if (!num && !arg->precision && arg->dot)
	{
		free(str);
		str = ft_strdup("");
	}
	if (num == 0)
		arg->hash = 0;
	if (arg->precision < (int) ft_strlen(str))
		arg->precision = (int) ft_strlen(str);
	if (arg->minus)
		ft_withminus(arg, string, str);
	else
		ft_withoutminus(arg, string, str);
	free(str);
}

static void	ft_withminus(t_arg *arg, t_string *string, char *content)
{
	if (arg->hash)
	{
		ft_printstr("0X", string);
		arg->width -= 2;
	}
	while (arg->precision > (int) ft_strlen(content))
	{
		ft_printchar('0', string);
		arg->width--;
		arg->precision--;
	}
	while (*content)
	{
		ft_printchar(*content++, string);
		arg->width--;
	}
	while (arg->width > 0)
	{
		ft_printchar(' ', string);
		arg->width--;
	}
}

static void	ft_withoutminus(t_arg *arg, t_string *string, char *content)
{
	if (!arg->zero)
	{
		while (arg->width > arg->precision)
		{
			ft_printchar(' ', string);
			arg->width--;
		}
	}
	if (arg->hash)
	{
		ft_printstr("0X", string);
		arg->width -= 2;
	}
	if (arg->zero)
	{
		while (arg->width > arg->precision)
		{
			ft_printchar('0', string);
			arg->width--;
		}
	}
	ft_finish(arg, string, content);
}

static void	ft_finish(t_arg *arg, t_string *string, char *content)
{
	while (arg->precision > (int) ft_strlen(content))
	{
		ft_printchar('0', string);
		arg->precision--;
	}
	while (*content)
		ft_printchar(*content++, string);
}
