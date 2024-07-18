/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 03:47:43 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/18 06:55:09 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include "defines.h"

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
	int		bitspp;
	int		line_size;
	int		endian;
	int		*pixels;
	int		width;
	int		height;
}	t_img;

typedef struct s_map
{
	char		*n_path;
	char		*s_path;
	char		*e_path;
	char		*w_path;
	char		**f_map;
	int			p_position[XY];
	char		p_direction;
	int			rows;
	int			columns;
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
	int		move[XY];
	int		rotate;
}	t_player;

typedef struct s_screen
{
	t_img	*north;
	t_img	*east;
	t_img	*south;
	t_img	*west;
	t_img	*info;
	int		ceiling;
	int		floor;
}	t_screen;

typedef struct s_mm
{
	int		minimap_pos[XY];
	int		block_size;
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
	double	delta_dist[XY];
	double	side_dist[XY];
	double	step[XY];
	double	perp_wall_dist;
	double	camera_x;
	double	wall_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		side;
}	t_ray;

typedef struct s_data
{
	void		*conn;
	void		*win;
	t_screen	*screen;
	t_map		*map;
	t_player	*player;
	t_mm		*mm;
	t_ray		*ray;
}	t_data;

#endif