/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:00:33 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/15 06:30:06 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

void	set_screen_info(t_data *data, t_screen *screen)
{
	screen->info = ft_calloc(1, sizeof(t_img));
	screen->info->img_ptr = mlx_new_image(data->conn, WIN_W, WIN_H);
	screen->info->data = (int *)mlx_get_data_addr(screen->info->img_ptr,
			&screen->info->bitspp,
			&screen->info->line_size,
			&screen->info->endian);
}

void	window_start(t_data *data)
{
	data->conn = mlx_init();
	if (!data->conn)
		exit_program("mlx Connection failed", data);
	data->win = mlx_new_window(data->conn, WIN_W, WIN_H, "CVb3D");
	if (!data->win)
		exit_program("Window start failed", data);
}

void	set_player_values(t_data *data)
{
	data->player->pos[X] = data->map->p_position[X] + 0.5;
	data->player->pos[Y] = data->map->p_position[Y] + 0.5;
	if (data->map->p_direction == 'N')
	{
		data->player->dir[Y] = -1;
		data->player->plane[X] = 0.66;
	}
	else if (data->map->p_direction == 'S')
	{
		data->player->dir[Y] = 1;
		data->player->plane[X] = -0.66;
	}
	else if (data->map->p_direction == 'E')
	{
		data->player->dir[X] = 1;
		data->player->plane[Y] = 0.66;
	}
	else if (data->map->p_direction == 'W')
	{
		data->player->dir[X] = -1;
		data->player->plane[Y] = -0.66;
	}
}

void	init_data(t_data **data, char *path)
{
	*data = ft_calloc(sizeof(t_data), 1);
	(*data)->map = ft_calloc(sizeof(t_map), 1);
	(*data)->map->textures = ft_calloc(sizeof(t_textures), 1);
	(*data)->screen = ft_calloc(sizeof(t_screen), 1);
	(*data)->player = ft_calloc(sizeof(t_player), 1);
	(*data)->mm = ft_calloc(sizeof(t_mm), 1);
	(*data)->rayc = ft_calloc(sizeof(t_rayc), 1);
	(*data)->map->file = ft_calloc(sizeof(t_file), 1);
	(*data)->map->raw_lines = ft_calloc(sizeof(t_rawlines), 1);
	(*data)->map->file->path = path;
}
