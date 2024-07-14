/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_central.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:28:13 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/14 02:47:32 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static void	check_line_amount(t_data *data)
{
	t_file	*f;
	int		size;
	char	*line;

	size = 0;
	f = data->map->file;
	f->fd = open(f->path, O_RDONLY);
	if (f->fd < 0)
		exit_program("Invalid file path", data);
	line = get_next_line(f->fd);
	while (line)
	{
		size++;
		free(line);
		line = get_next_line(f->fd);
	}
	f->lines = size;
	close(f->fd);
}

static char	**get_rest(t_data *data, char **lines, int i)
{
	char		**map;
	int			j;

	map = ft_calloc(sizeof(char *), data->map->file->lines - i + 1);
	j = 0;
	while (lines[i])
	{
		map[j] = ft_strdup(lines[i]);
		i++;
		j++;
	}
	return (map);
}

static void	extract_map(t_data *data, int i)
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
		increment_ph_fetch(data, ph, trimmed);
		free(trimmed);
		if (complete_ph(ph))
			break ;
		i++;
	}
	data->map->f_map = get_rest(data, lines, i + 1);
	free(ph);
}

static void	fetch_file(t_data *data)
{
	t_file	*f;
	char	*line;
	int		i;

	i = 0;
	f = data->map->file;
	check_line_amount(data);
	data->map->file->fd = open(f->path, O_RDONLY);
	f->raw_text = ft_calloc(sizeof(char *), (f->lines + 1));
	line = get_next_line(f->fd);
	while (line)
	{
		f->raw_text[i++] = line;
		line = get_next_line(f->fd);
	}
	close(f->fd);
}

void	parsing_stuff(t_data *data)
{
	if (ft_strcmp(".cub", ft_strrchr(data->map->file->path, '.')))
		exit_program("Invalid file extension", data);
	fetch_file(data);
	check_valid_format(data, 0);
	extract_map(data, 0);
	check_map_files(data);
	check_rgb(data);
	validate_map_info(data, data->map->f_map);
}
