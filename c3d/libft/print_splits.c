/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_splits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:46:42 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/14 05:27:41 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_splits(char **splits)
{
	int	i;

	if (!splits)
		return ;
	i = 0;
	while (splits[i])
	{
		ft_printf("%s\n", splits[i]);
		i++;
	}
}
