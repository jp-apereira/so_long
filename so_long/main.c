/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:18:09 by joaopereira       #+#    #+#             */
/*   Updated: 2023/08/13 22:18:51 by joaopereira      ###   ########.fr       */
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
	fla_game.initmlx = mlx_init();
	fla_game.winmlx = mlx_new_window(draco.initmlx, (draco.map_width
				* 64), (draco.map_height * 64), "DRACO GAME");
	init_images(&draco);
	mlx_key_hook(draco.winmlx, &control, &draco);
	mlx_hook(draco.winmlx, 17, 0L, (void *)exit_game, &draco);
	mlx_loop(draco.initmlx);
	return (0);
}