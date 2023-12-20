/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-p <jalves-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:18:09 by joaopereira       #+#    #+#             */
/*   Updated: 2023/09/05 10:46:40 by jalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game game;

	check_ac(ac);
	ft_memset(&game, 0, sizeof(t_game));
	read_map(&game, av[1]);
	check_errors(&game);
	game.initmlx = mlx_init();
	game.winmlx = mlx_new_window(game.initmlx, (game.map_width * 32),
		(game.map_height * 32), "MY GAME");
	init_images(&game);
	mlx_key_hook(game.winmlx, &controls, &game);
	mlx_hook(game.winmlx, 17, 0L, (void *)exit_game, &game);
	mlx_loop(game.initmlx);
	return (0);
}