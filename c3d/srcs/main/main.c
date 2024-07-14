/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 05:11:45 by hescoval          #+#    #+#             */
/*   Updated: 2024/07/14 06:18:44 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/c3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		exit_program("Wrong number of arguments", NULL);
	init_data(&data, av[1]);
	parsing_stuff(data);
	printf("%s\n", data->map->file->path);
	exit_program(NULL, data);
}
