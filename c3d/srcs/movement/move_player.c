/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:07:20 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 23:35:27 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

int	move_forward(t_data *data)
{
	if (data->map->f_map[(int)(data->player->pos[X] + data->player->dir[X]
			* (MOVE_SPEED + 0.25))][(int)(data->player->pos[Y])] != '1')
		data->player->pos[X] += data->player->dir[X] * MOVE_SPEED;
	if (data->map->f_map[(int)(data->player->pos[X])][(int)(data->player->pos[Y]
			+ data->player->dir[Y] * (MOVE_SPEED + 0.25))] != '1')
		data->player->pos[Y] += data->player->dir[Y] * MOVE_SPEED;
	return (1);
}

int	move_back(t_data *data)
{
	if (data->map->f_map[(int)(data->player->pos[X] - data->player->dir[X]
			* (MOVE_SPEED + 0.25))][(int)(data->player->pos[Y])] != '1')
		data->player->pos[X] -= data->player->dir[X] * MOVE_SPEED;
	if (data->map->f_map[(int)(data->player->pos[X])][(int)(data->player->pos[Y]
		- data->player->dir[Y] * (MOVE_SPEED + 0.25))] != '1')
		data->player->pos[Y] -= data->player->dir[Y] * MOVE_SPEED;
	return (-1);
}

int	move_right(t_data *data)
{
	double	perp_dir[XY];

	perp_dir[X] = data->player->dir[Y];
	perp_dir[Y] = -data->player->dir[X];
	if (data->map->f_map[(int)(data->player->pos[X] + perp_dir[X]
			* (MOVE_SPEED + 0.25))][(int)(data->player->pos[Y])] != '1')
		data->player->pos[X] += perp_dir[X] * MOVE_SPEED;
	if (data->map->f_map[(int)(data->player->pos[X])][(int)(data->player->pos[Y]
		+ perp_dir[Y] * (MOVE_SPEED + 0.25))] != '1')
		data->player->pos[Y] += perp_dir[Y] * MOVE_SPEED;
	return (1);
}

int	move_left(t_data *data)
{
	double	perp_dir[XY];

	perp_dir[X] = -data->player->dir[Y];
	perp_dir[Y] = data->player->dir[X];
	if (data->map->f_map[(int)(data->player->pos[X] + perp_dir[X]
			* (MOVE_SPEED + 0.25))][(int)(data->player->pos[Y])] != '1')
		data->player->pos[X] += perp_dir[X] * MOVE_SPEED;
	if (data->map->f_map[(int)(data->player->pos[X])][(int)(data->player->pos[Y]
			+ perp_dir[Y] * (MOVE_SPEED + 0.25))] != '1')
		data->player->pos[Y] += perp_dir[Y] * MOVE_SPEED;
	return (-1);
}

void	movement_handle(t_data *data)
{
	if (data->player->move[Y] == 1)
		move_forward(data);
	if (data->player->move[Y] == -1)
		move_back(data);
	if (data->player->move[X] == 1)
		move_right(data);
	if (data->player->move[X] == -1)
		move_left(data);
	if (data->player->rotate >= 1)
		rotate_right(data);
	if (data->player->rotate <= -1)
		rotate_left(data);
}
