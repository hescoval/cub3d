/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:58:36 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/13 04:28:29 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_H
# define C3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "../libft/libft.h"

# define X 0
# define Y 1
# define XY 2
# define RGB 3
# define R 0
# define G 1
# define B 2
# define PI 3.14159265358979323846

typedef struct s_parsehelp
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
	int	map_found;
	int	throw_error;
}	t_parsehelp;

typedef struct s_rawlines
{
	char	*no_line;
	char	*so_line;
	char	*we_line;
	char	*ea_line;
	char	*f_line;
	char	*c_line;
}	t_rawlines;

typedef struct s_file
{
	char	*path;
	int		fd;
	int		lines;
	char	**raw_text;
}	t_file;

typedef struct s_textures
{
	void		*texture_img;
	char		*texture_data;
	int			texture_width;
	int			texture_height;
	int			texture_bits_per_pixel;
	int			texture_line_length;
	int			texture_endian;
}	t_textures;

typedef struct s_img
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		*data;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	int			floor[RGB];
	int			ceiling[RGB];
	char		**f_map;
	int			p_position[XY];
	char		p_direction;
	int			rows;
	int			columns;
	int			start_map;
	int			n_textures;
	t_rawlines	*raw_lines;
	t_file		*file;
	t_textures	*textures;
	t_img		*text_imgs;
}	t_map;

typedef struct s_player
{
	double	pos[XY];
	double	dir[XY];
	double	plane[XY];
	double	speed;
	double	rotation;
	int		fov;
}	t_player;

typedef struct s_screen
{
	t_img	*screen;
	t_img	*north;
	t_img	*east;
	t_img	*south;
	t_img	*west;
	int		ceiling;
	int		floor;
	int		height;
	int		width;
}	t_screen;

typedef struct s_mm
{
	t_img	*bkg;
	t_img	*player;
	t_img	*wall;
	t_img	*floor;
}	t_mm;

typedef struct s_ray
{
	double	pos[XY];
	double	dir[XY];
	double	plane[XY];
	double	ray_dir[XY];
	int		tile[XY];
	double	delta_distance[XY];
	double	side_distance[XY];
	double	step[XY];
	double	perp_wall_distance;
	double	camera_x;
	double	wall_x;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_rayc
{
	t_ray	ray;
	double	time;
	double	old_time;
}	t_rayc;

typedef struct s_data
{
	void		*conn;
	void		*win;
	t_screen	*screen;
	t_map		*map;
	t_player	*player;
	t_mm		*mm;
	t_rayc		*rayc;
}	t_data;

// Frees and inits

void	exit_program(char *error, t_data *to_free);
void	init_data(t_data **to_free, char *path);
void	free_stuff(t_data *to_free);

// Parsing stuff
void	parsing_stuff(t_data *data);
int		complete_ph(t_parsehelp *ph);
void	increment_ph(t_parsehelp *ph, char *line);
void	check_valid_format(t_data *data, int i);
void	increment_ph_fetch(t_data *data, t_parsehelp *ph, char *line);
void	check_map_files(t_data *data);

#endif