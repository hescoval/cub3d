/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 06:19:10 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/18 10:30:52 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static void	square_to_image(t_data *data, t_img *to_print, int prints)
{
	int	x;
	int	y;

	x = data->mm->minimap_pos[X];
	y = data->mm->minimap_pos[Y];
	mlx_put_image_to_window(data->conn,
		data->win,
		to_print->img_ptr,
		x + (prints % (MINIMAP_SIZE * 2) * data->mm->block_size),
		y + (prints / (MINIMAP_SIZE * 2) * data->mm->block_size));
}

static void	print_math(t_data *data, int *to_check, int *coords, int prints)
{
	if (to_check[X] == coords[X] && to_check[Y] == coords[Y])
		square_to_image(data, data->mm->player, prints);
	else if (to_check[X] < 0
		|| to_check[X] >= data->map->columns
		|| to_check[Y] < 0
		|| to_check[Y] >= data->map->rows)
		square_to_image(data, data->mm->floor, prints);
	else if (data->map->f_map[to_check[Y]][to_check[X]] == '1')
		square_to_image(data, data->mm->wall, prints);
	else
		square_to_image(data, data->mm->floor, prints);
}

static void	display_map(t_data *data, int *coords)
{
	int	help[2];
	int	prints;
	int	checks[2];

	prints = 0;
	help[0] = -MINIMAP_SIZE;
	while (help[0] < MINIMAP_SIZE)
	{
		help[1] = -MINIMAP_SIZE;
		while (help[1] < MINIMAP_SIZE)
		{
			checks[X] = coords[X] + help[1];
			checks[Y] = coords[Y] + help[0];
			print_math(data, checks, coords, prints);
			help[1]++;
			prints++;
		}
		help[0]++;
	}
}

void	minimap(t_data *data)
{
	int		p_coords[XY];

	p_coords[X] = (int)data->player->pos[Y];
	p_coords[Y] = (int)data->player->pos[X];
	display_map(data, p_coords);
}

void	make_mm_images(t_data *data, t_mm *mm, t_img *target, int color)
{
	target->img_ptr = mlx_new_image(data->conn,
			mm->block_size,
			mm->block_size);
	target->pixels = (int *)mlx_get_data_addr(target->img_ptr,
			&target->bitspp,
			&target->line_size,
			&target->endian);
	pixel_put(target->pixels, color, mm->block_size * mm->block_size);
}
