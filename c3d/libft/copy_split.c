/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 05:33:08 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/14 06:11:17 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_split(char **src, int height)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(char *) * (height + 1));
	i = 0;
	while (src[i])
	{
		copy[i] = ft_strdup(src[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
