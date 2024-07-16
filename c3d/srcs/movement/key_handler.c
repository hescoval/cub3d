/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 04:26:25 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 11:18:53 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/c3d.h"

static int	key_press(int key, t_data *data)
{
	if (key == XK_Escape)
		exit_program(NULL, data);
	if (key == XK_Left)
		data->player->rotate -= 1;
	if (key == XK_Right)
		data->player->rotate += 1;
	if (key == XK_w)
		data->player->move[Y] = 1;
	if (key == XK_a)
		data->player->move[X] = -1;
	if (key == XK_s)
		data->player->move[Y] = -1;
	if (key == XK_d)
		data->player->move[X] = 1;
	return (0);
}

static int	key_release(int key, t_data *data)
{
	if (key == XK_Escape)
		exit_program(NULL, data);
	if (key == XK_w && data->player->move[Y] == 1)
		data->player->move[Y] = 0;
	if (key == XK_s && data->player->move[Y] == -1)
		data->player->move[Y] = 0;
	if (key == XK_a && data->player->move[X] == -1)
		data->player->move[X] += 1;
	if (key == XK_d && data->player->move[X] == 1)
		data->player->move[X] -= 1;
	if (key == XK_Left && data->player->rotate <= 1)
		data->player->rotate = 0;
	if (key == XK_Right && data->player->rotate >= -1)
		data->player->rotate = 0;
	return (0);
}

void	key_hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_hook(data->win, WindowClose, WindowCloseMask, window_close, data);
}
