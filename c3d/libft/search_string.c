/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 02:57:23 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/14 04:10:01 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search_string(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (not_in_set(set, str[i]))
			return (0);
		i++;
	}
	return (1);
}
