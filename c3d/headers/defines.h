/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 03:00:16 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/16 10:31:29 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define X 0
# define Y 1
# define XY 2
# define PI 3.14159265358979323846
# define KeyPress 2
# define KeyRelease 3
# define WindowClose 17
# define WindowCloseMask 1L << 17
# define TEX_SIZE 64

// Window settings
# define WIN_H 768
# define WIN_W 1024
# define WIN_NAME "Wolfenstein Wannabe"

# define HALF_SCREEN (WIN_W * (WIN_H / 2))

// Player settings
# define MOVE_SPEED 0.01
# define ROT_SPEED 0.025

#endif