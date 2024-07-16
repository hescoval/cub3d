/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:16:53 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 11:04:28 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static void transfer_coords(t_ray *ray, t_player *player)
{
	ray->dir[X] = player->dir[X];
	ray->dir[Y] = player->dir[Y];
	ray->pos[X] = player->pos[Y];
	ray->pos[Y] = player->pos[X];
	ray->plane[X] = player->plane[X];
	ray->plane[Y] = player->plane[Y];
}

static void	step_and_sidedist(t_ray *ray, int axis)
{
	ray->tile[axis] = (int) ray->pos[axis];
	if (ray->ray_dir[axis] < 0)
	{
		ray->step[axis] = -1;
		ray->side_dist[axis] = (ray->pos[axis] - ray->tile[axis])
			* ray->delta_dist[axis];
	}
	else
	{
		ray->step[axis] = 1;
		ray->side_dist[axis] = (ray->tile[axis] + 1.0 - ray->pos[axis])
			* ray->delta_dist[axis];
	}
}

static void setup_ray(t_ray *ray, int ray_x)
{
	ray->camera_x = 2 * ray_x / (double)WIN_W - 1;
	ray->ray_dir[X] = ray->dir[X] + ray->plane[X] * ray->camera_x;
	ray->ray_dir[Y] = ray->dir[Y] + ray->plane[Y] * ray->camera_x;
	if (ray->ray_dir[X] == 0)
		ray->delta_dist[X] = 1e30;
	else
		ray->delta_dist[X] = fabs(1 / ray->ray_dir[X]);
	if (ray->ray_dir[Y] == 0)
		ray->delta_dist[Y] = 1e30;
	else
		ray->delta_dist[Y] = fabs(1 / ray->ray_dir[Y]);
	step_and_sidedist(ray, X);
	step_and_sidedist(ray, Y);
}

void	raycasting(t_data *data)
{
	int	i;

	i = 0;
	transfer_coords(data->ray, data->player);
	while (i < WIN_W)
	{
		setup_ray(data->ray, i);
		dda(data->ray, data->map);
		draw_setup(data, data->ray, i);
		i++;
	}
}