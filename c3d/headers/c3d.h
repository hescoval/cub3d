/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:58:36 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 11:16:29 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_H
# define C3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"

# include <X11/keysym.h>
# include <X11/X.h>

# include "../libft/libft.h"
# include "defines.h"
# include "structs.h"

// Frees and inits

void	exit_program(char *error, t_data *to_free);
void	init_data(t_data **to_free, char *path);
void	free_stuff(t_data *to_free);
void	set_player_values(t_data *data);
void	window_start(t_data *data);
void	clean_window_close(t_data *to_free);
void	set_screen_info(t_data *data, t_screen *screen);

// Parsing stuff
void	parsing_stuff(t_data *data);
int		complete_ph(t_parsehelp *ph);
void	increment_ph(t_parsehelp *ph, char *line);
void	check_valid_format(t_data *data, int i);
void	increment_ph_fetch(t_data *data, t_parsehelp *ph, char *line);
void	check_map_files(t_data *data);
void	validate_map_info(t_data *data, char **map);
void	check_rgb(t_data *data);
void	set_rgb_values(char **values, t_data *data, int *rgb);
void	pad_map(t_data *data, char **map);

//Texture loading
void	fetch_textures(t_data *data);

//Movement Related Functions
void	key_hooks(t_data *data);

//Window Related Functions

int		window_close(t_data *data);

// Rendering

void	initial_render(t_data *data);
int		rendering(t_data *data);
void	draw_setup(t_data *data , t_ray *ray, int ray_x);

// Raycasting

void	raycasting(t_data *data);
void	dda(t_ray *ray, t_map *map);

//Movement

void movement_handle(t_data *data);


#endif