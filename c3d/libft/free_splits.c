/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 05:00:27 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/12 07:34:17 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_splits(char **to_free)
{
	int	i;

	i = 0;
	if (!to_free)
		return ;
	while (to_free[i])
		free(to_free[i++]);
	free(to_free);
}
