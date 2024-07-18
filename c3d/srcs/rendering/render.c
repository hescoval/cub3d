/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 07:09:31 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/18 10:30:37 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

void	pixel_put(void	*start_pixel, int desired_color, int pixel_amount)
{
	int	i;
	int	*cast;

	cast = (int *)start_pixel;
	i = 0;
	while (i < pixel_amount)
	{
		cast[i] = desired_color;
		i++;
	}
}

static void	initial_render(t_data *data)
{
	int	half_screen;
	int	*cast;

	cast = data->screen->info->pixels;
	half_screen = (WIN_W * (WIN_H / 2));
	pixel_put(data->screen->info->pixels, data->screen->ceiling, half_screen);
	pixel_put(&cast[half_screen], data->screen->floor, half_screen);
}

int	rendering(t_data *data)
{
	initial_render(data);
	raycasting(data);
	mlx_put_image_to_window(data->conn,
		data->win,
		data->screen->info->img_ptr,
		0,
		0);
	minimap(data);
	movement_handle(data);
	return (0);
}
