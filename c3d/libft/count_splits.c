/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_splits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 04:06:22 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/13 04:29:56 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_splits(char **splits)
{
	int	i;

	if (!splits)
		return (0);
	i = 0;
	while (splits[i])
		i++;
	return (i);
}
