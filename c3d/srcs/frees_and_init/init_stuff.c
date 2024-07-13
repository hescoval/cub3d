/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:00:33 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/13 03:41:14 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

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
