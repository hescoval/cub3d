/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:22:37 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/13 04:28:45 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static void	inc_dup(int *change, char **line, char *new_line)
{
	*line = ft_strdup(new_line);
	(*change)++;
}

int	complete_ph(t_parsehelp *ph)
{
	if (ph->no != 1 || ph->so != 1 || ph->we != 1
		|| ph->ea != 1 || ph->f != 1 || ph->c != 1)
		return (0);
	return (1);
}

void	increment_ph(t_parsehelp *ph, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		ph->no++;
	else if (!ft_strncmp(line, "SO", 2))
		ph->so++;
	else if (!ft_strncmp(line, "WE", 2))
		ph->we++;
	else if (!ft_strncmp(line, "EA", 2))
		ph->ea++;
	else if (!ft_strncmp(line, "F", 1))
		ph->f++;
	else if (!ft_strncmp(line, "C", 1))
		ph->c++;
	else if (!complete_ph(ph))
		ph->throw_error = 1;
	else
		ph->map_found = 1;
}

void	increment_ph_fetch(t_data *data, t_parsehelp *ph, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		inc_dup(&(ph->no), &(data->map->raw_lines->no_line), line);
	else if (!ft_strncmp(line, "SO", 2))
		inc_dup(&(ph->so), &(data->map->raw_lines->so_line), line);
	else if (!ft_strncmp(line, "WE", 2))
		inc_dup(&(ph->we), &(data->map->raw_lines->we_line), line);
	else if (!ft_strncmp(line, "EA", 2))
		inc_dup(&(ph->ea), &(data->map->raw_lines->ea_line), line);
	else if (!ft_strncmp(line, "F", 1))
		inc_dup(&(ph->f), &(data->map->raw_lines->f_line), line);
	else if (!ft_strncmp(line, "C", 1))
		inc_dup(&(ph->c), &(data->map->raw_lines->c_line), line);
}
