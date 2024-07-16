/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 07:15:16 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 07:29:34 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static void pixel_put(void	*start_pixel, int desired_color, int pixel_amount)
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

void	initial_render(t_data *data)
{
	pixel_put(data->screen->info->pixels, data->screen->ceiling, HALF_SCREEN);
	pixel_put(&data->screen->info->pixels[HALF_SCREEN], data->screen->floor, HALF_SCREEN);
}