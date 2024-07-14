/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 05:00:54 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/14 06:15:52 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static void	pad_line(t_data *data, char **map, int i)
{
	char	*new_line;
	int		start;

	start = ft_strlen(map[i]);
	new_line = ft_calloc(data->map->columns + 1, sizeof(char));
	if (!new_line)
		exit_program("Malloc failed", data);
	ft_strncpy(new_line, map[i], ft_strlen(map[i]));
	while (start < data->map->columns)
	{
		new_line[start] = '0';
		start++;
	}
	free(map[i]);
	map[i] = new_line;
}

void	pad_map(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) < data->map->columns)
			pad_line(data, map, i);
		i++;
	}
}
