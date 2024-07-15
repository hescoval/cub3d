/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:29:26 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/15 06:39:45 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

void	exit_program(char *error, t_data *to_free)
{
	if (to_free)
	{
		if (to_free->conn)
			clean_window_close(to_free);
		free_stuff(to_free);
	}
	if (!error)
		exit (SUCCESS_EXIT);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	exit (ERROR_EXIT);
}
