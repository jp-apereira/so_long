/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-p <jalves-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:30:20 by jalves-p          #+#    #+#             */
/*   Updated: 2023/08/14 16:30:48 by jalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	read_map(&game, argv[1]);
	if (!check_errors(&game, argv[1], argc))
	{
		ft_free(game.map);
		return (0);
	}
	game.initmlx = mlx_init();
	game.winmlx = mlx_new_window(game.initmlx, (game.map_width * 64),
			(game.map_height * 64), "DRACO");
	init_images(&game);
	mlx_key_hook(game.winmlx, &controls, &game);
	mlx_hook(game.winmlx, 17, 0L, (void *)exit_game, &game);
	mlx_loop(game.initmlx);
	return (0);
}