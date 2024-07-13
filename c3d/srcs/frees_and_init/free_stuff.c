/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 06:42:40 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/13 04:28:37 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

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
	safe_free(map->north);
	safe_free(map->south);
	safe_free(map->east);
	safe_free(map->west);
	safe_free(map->file);
	safe_free(map);
}

void	free_stuff(t_data *to_free)
{
	free_map_stuff(to_free->map);
	safe_free(to_free->player);
	safe_free(to_free->mm);
	safe_free(to_free->rayc);
	safe_free(to_free->screen);
	safe_free(to_free);
}
