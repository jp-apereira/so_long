/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:18:09 by joaopereira       #+#    #+#             */
/*   Updated: 2023/08/24 17:59:55 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	draco;

	check_ac(ac);
	ft_memset(&draco, 0, sizeof(t_game));
	read_map(&draco, av[1]);
	check_errors(&draco);
	draco.initmlx = mlx_init();
	draco.winmlx = mlx_new_window(draco.initmlx, (draco.map_width
				* 32), (draco.map_height * 32), "DRACO GAME");
	init_images(&draco);
	mlx_key_hook(draco.winmlx, &controls, &draco);
	mlx_hook(draco.winmlx, 17, 0L, (void *)exit_game, &draco);
	mlx_loop(draco.initmlx);
	return (0);
}