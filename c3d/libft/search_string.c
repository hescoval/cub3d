/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 02:57:23 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/13 04:30:09 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search_string(char *str, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
