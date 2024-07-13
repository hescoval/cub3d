/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_error_checking.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:51:36 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/13 04:29:15 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

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
