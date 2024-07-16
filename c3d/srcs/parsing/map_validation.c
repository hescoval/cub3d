/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 19:59:34 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 23:16:43 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static void	flood_fill(t_data *data, char **input, int x, int y)
{
	if (input[y][x] == '1' || input[y][x] == 'C')
		return ;
	if (x == 0
		|| y == 0
		|| x == data->map->columns - 1
		|| y == data->map->rows - 1)
	{
		free_splits(input);
		exit_program("Map not closed", data);
	}
	input[y][x] = 'C';
	flood_fill(data, input, x + 1, y);
	flood_fill(data, input, x - 1, y);
	flood_fill(data, input, x, y + 1);
	flood_fill(data, input, x, y - 1);
}

static void	find_player(t_data *data, char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!not_in_set("NSEW", map[i][j]))
			{
				if (data->map->p_position[X] != 0)
					exit_program("Multiple players in map", data);
				data->map->p_position[X] = i;
				data->map->p_position[Y] = j;
				data->map->p_direction = map[i][j];
				map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (data->map->p_position[X] == 0)
		exit_program("Invalid Player Position", data);
}

static void	valid_characters(t_data *data, char **map)
{
	int	i;
	int	biggest_line;

	i = 0;
	while (map[i])
	{
		biggest_line = ft_strlen(map[i]);
		if (biggest_line > data->map->columns)
			data->map->columns = biggest_line;
		if (search_string(map[i], " 01NSEW\n"))
			i++;
		else
			exit_program("Invalid characters in map", data);
	}
	data->map->rows = i;
}

void	validate_map_info(t_data *data, char **map)
{
	char	**copy;

	valid_characters(data, map);
	find_player(data, map, 0, 0);
	pad_map(data, map);
	copy = copy_split(map, data->map->rows);
	flood_fill(data, copy, data->map->p_position[Y], data->map->p_position[X]);
	free_splits(copy);
}
