/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_more_stuff.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 05:53:42 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/18 23:23:27 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static t_img	*safe_load(t_data *data, char *path)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	img->img_ptr = mlx_xpm_file_to_image(data->conn,
			path,
			&img->width,
			&img->height);
	if (!img->img_ptr)
	{
		safe_free(img);
		exit_program("XPM file couldn't be loaded properly", data);
	}
	img->pixels = (int *)mlx_get_data_addr(img->img_ptr,
			&img->bitspp,
			&img->line_size,
			&img->endian);
	return (img);
}

void	fetch_textures(t_data *data)
{
	data->screen->north = safe_load(data, data->map->n_path);
	data->screen->south = safe_load(data, data->map->s_path);
	data->screen->east = safe_load(data, data->map->e_path);
	data->screen->west = safe_load(data, data->map->w_path);
}

void	init_mm_info(t_data *data, t_mm *mm)
{
	int	block;

	block = mm->block_size;
	mm->floor = ft_calloc(1, sizeof(t_img));
	mm->wall = ft_calloc(1, sizeof(t_img));
	mm->player = ft_calloc(1, sizeof(t_img));
	mm->minimap_pos[Y] = WIN_H * 0.05;
	mm->block_size = WIN_W * 0.02;
	mm->minimap_pos[X] = WIN_W * (1 - 0.05) - (block * MINIMAP_SIZE * 2);
	make_mm_images(data, mm, mm->floor, FLOOR_COLOR);
	make_mm_images(data, mm, mm->wall, WALL_COLOR);
	make_mm_images(data, mm, mm->player, PLAYER_COLOR);
}
