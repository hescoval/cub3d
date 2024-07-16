/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:01:06 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 23:31:05 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static void	check_wall_column(t_ray *ray, int axis)
{
	ray->wall_x = ray->pos[axis] + ray->perp_wall_dist * ray->ray_dir[axis];
	ray->wall_x -= floor(ray->wall_x);
}

static void	draw_wall(t_data *data, t_ray *ray, t_img *target_tex, int ray_x)
{
	int	screen_y;
	int	tex[XY];

	tex[X] = (int)(data->ray->wall_x * (double)TEX_SIZE);
	while (++(ray->draw_start) < ray->draw_end)
	{
		screen_y = ray->draw_start - WIN_H / 2 + ray->line_height / 2;
		tex[Y] = screen_y * 64 / ray->line_height;
		data->screen->info->pixels[ray_x + ray->draw_start
			* (data->screen->info->line_size / 4)]
			= target_tex->pixels[tex[X] + tex[Y] * 64];
	}
}

static t_img	*target_texture(t_data *data, t_ray *ray)
{
	if (ray->side == Y)
	{
		if (ray->ray_dir[Y] <= 0)
			return (data->screen->south);
		else
			return (data->screen->north);
	}
	else
	{
		if (ray->ray_dir[X] > 0)
			return (data->screen->east);
		else
			return (data->screen->west);
	}
}

void	draw_setup(t_data *data, t_ray *ray, int ray_x)
{
	t_img	*texture;

	ray->line_height = (int)(WIN_H / ray->perp_wall_dist);
	texture = target_texture(data, ray);
	ray->draw_start = -ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = -1;
	ray->draw_end = ray->line_height / 2 + WIN_H / 2;
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
	if (data->ray->side == 0)
		check_wall_column(ray, Y);
	else
		check_wall_column(ray, X);
	draw_wall(data, ray, texture, ray_x);
}
