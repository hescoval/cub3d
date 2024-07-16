/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 08:32:47 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 10:42:13 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

void	dda(t_ray *ray, t_map *map)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta_dist[X];
			ray->tile[X] += ray->step[X];
			ray->side = X;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[Y];
			ray->tile[Y] += ray->step[Y];
			ray->side = Y;
		}
		if (map->f_map[ray->tile[X]][ray->tile[Y]] == '1')
			hit = 1;
	}
	if (ray->side == X)
		ray->perp_wall_dist = (ray->side_dist[X] - ray->delta_dist[X]);
	else
		ray->perp_wall_dist = (ray->side_dist[Y] - ray->delta_dist[Y]);
}
