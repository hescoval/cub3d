/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:36:05 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 23:34:26 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

int	rotate_left(t_data *data)
{
	double	old_dir[XY];
	double	old_plane[X];

	old_dir[X] = data->player->dir[X];
	data->player->dir[X] = data->player->dir[X]
		* cos(ROT_SPEED) - data->player->dir[Y]
		* sin(ROT_SPEED);
	data->player->dir[Y] = old_dir[X] * sin(ROT_SPEED)
		+ data->player->dir[Y]
		* cos(ROT_SPEED);
	old_plane[X] = data->player->plane[X];
	data->player->plane[X] = data->player->plane[X]
		* cos(ROT_SPEED) - data->player->plane[Y]
		* sin(ROT_SPEED);
	data->player->plane[Y] = old_plane[X] * sin(ROT_SPEED)
		+ data->player->plane[Y] * cos(ROT_SPEED);
	return (-1);
}

int	rotate_right(t_data *data)
{
	double	old_dir[X];
	double	old_plane[X];

	old_dir[X] = data->player->dir[X];
	data->player->dir[X] = data->player->dir[X] * cos(-ROT_SPEED)
		- data->player->dir[Y] * sin(-ROT_SPEED);
	data->player->dir[Y] = old_dir[X] * sin(-ROT_SPEED)
		+ data->player->dir[Y] * cos(-ROT_SPEED);
	old_plane[X] = data->player->plane[X];
	data->player->plane[X] = data->player->plane[X]
		* cos(-ROT_SPEED) - data->player->plane[Y]
		* sin(-ROT_SPEED);
	data->player->plane[Y] = old_plane[X] * sin(-ROT_SPEED)
		+ data->player->plane[Y] * cos(-ROT_SPEED);
	return (1);
}
