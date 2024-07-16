/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 07:09:31 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 11:06:29 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

int	rendering(t_data *data)
{
	initial_render(data);
	raycasting(data);
	movement_handle(data);
	mlx_put_image_to_window(data->conn, data->win, data->screen->info->img_ptr, 0, 0);
	return (0);
}