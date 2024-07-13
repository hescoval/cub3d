/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:29:26 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/13 01:41:47 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

void	exit_program(char *error, t_data *to_free)
{
	if (error)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(error, 2);
	}
	free_stuff(to_free);
	exit (1);
}
