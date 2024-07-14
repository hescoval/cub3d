/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:51:36 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/14 03:14:47 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static void	validate_rgb_line(char *line, t_data *data, int *target_array)
{
	char	**space_split;
	char	*valid;

	valid = "0123456789+-";
	ft_replace(line, ',', ' ');
	space_split = ft_split(line, ' ');
	if (count_splits(space_split) != 4)
	{
		free_splits(space_split);
		exit_program("Invalid RGB line", data);
	}
	if (!search_string(space_split[1], valid)
		|| !search_string(space_split[2], valid)
		|| !search_string(space_split[3], valid))
	{
		free_splits(space_split);
		exit_program("Invalid RGB values", data);
	}
	set_rgb_values(space_split, data, target_array);
	free_splits(space_split);
}

static void	open_close_check(t_data *data, char **path, char *line)
{
	int		fd;
	char	**free;

	free = ft_split(line, ' ');
	if (count_splits(free) != 2)
	{
		free_splits(free);
		exit_program("Invalid path in textures", data);
	}
	if (ft_strcmp(".xpm", ft_strrchr(free[1], '.')))
	{
		free_splits(free);
		exit_program("Invalid texture path extension", data);
	}
	fd = open(free[1], O_RDONLY);
	if (fd < 0)
	{
		free_splits(free);
		exit_program("Can't access/open path in textures", data);
	}
	close(fd);
	*path = ft_strdup(free[1]);
	free_splits(free);
}

void	check_map_files(t_data *data)
{
	t_rawlines	*rls;

	rls = data->map->raw_lines;
	open_close_check(data, &data->map->north, rls->no_line);
	open_close_check(data, &data->map->south, rls->so_line);
	open_close_check(data, &data->map->west, rls->we_line);
	open_close_check(data, &data->map->east, rls->ea_line);
}

void	check_valid_format(t_data *data, int i)
{
	char		**lines;
	char		*trimmed;
	t_parsehelp	*ph;

	ph = ft_calloc(sizeof(t_parsehelp), 1);
	lines = data->map->file->raw_text;
	while (lines[i])
	{
		if (empty_line(lines[i]))
		{
			i++;
			continue ;
		}
		trimmed = ft_strtrim(lines[i], " \t\n");
		increment_ph(ph, trimmed);
		free(trimmed);
		i++;
	}
	if (!complete_ph(ph) || ph->throw_error || !ph->map_found)
	{
		free(ph);
		exit_program("Invalid map format", data);
	}
	free(ph);
}

void	check_rgb(t_data *data)
{
	t_screen	*scr;

	scr = data->screen;
	validate_rgb_line(data->map->raw_lines->f_line, data, &scr->floor);
	validate_rgb_line(data->map->raw_lines->c_line, data, &scr->ceiling);
}
