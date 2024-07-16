/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:42:40 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 08:22:40 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static void	free_img_struct(t_data *data, t_img *img)
{
	if (!img)
		return ;
	if (img->img_ptr)
		mlx_destroy_image(data->conn, img->img_ptr);
	safe_free(img);
}

static void	free_raw_lines(t_rawlines *raw_lines)
{
	safe_free(raw_lines->no_line);
	safe_free(raw_lines->so_line);
	safe_free(raw_lines->we_line);
	safe_free(raw_lines->ea_line);
	safe_free(raw_lines->f_line);
	safe_free(raw_lines->c_line);
}

static void	free_map_stuff(t_map *map)
{
	free_raw_lines(map->raw_lines);
	free_splits(map->file->raw_text);
	free_splits(map->f_map);
	safe_free(map->raw_lines);
	safe_free(map->textures);
	safe_free(map->text_imgs);
	safe_free(map->n_path);
	safe_free(map->s_path);
	safe_free(map->e_path);
	safe_free(map->w_path);
	safe_free(map->file);
	safe_free(map);
}

void	clean_window_close(t_data *to_free)
{
	free_img_struct(to_free, to_free->screen->info);
	free_img_struct(to_free, to_free->screen->north);
	free_img_struct(to_free, to_free->screen->south);
	free_img_struct(to_free, to_free->screen->east);
	free_img_struct(to_free, to_free->screen->west);
	mlx_destroy_window(to_free->conn, to_free->win);
	mlx_destroy_display(to_free->conn);
	safe_free(to_free->conn);
}

void	free_stuff(t_data *to_free)
{
	free_map_stuff(to_free->map);
	safe_free(to_free->player);
	safe_free(to_free->mm);
	safe_free(to_free->screen);
	safe_free(to_free->ray);
	safe_free(to_free);
}
