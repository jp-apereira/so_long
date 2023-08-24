/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:10:14 by joaopereira       #+#    #+#             */
/*   Updated: 2023/08/24 18:01:24 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_game *game)
{
	mlx_destroy_image(game->initmlx, game->img.ptr);
	mlx_destroy_image(game->initmlx, game->wall.ptr);
	mlx_destroy_image(game->initmlx, game->player.ptr);
	mlx_destroy_image(game->initmlx, game->exit.ptr);
	mlx_destroy_image(game->initmlx, game->collect.ptr);
	mlx_destroy_image(game->initmlx, game->floor.ptr);
}

void	ft_free(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	exit_game(t_game *game)
{
	ft_free(game->map);
	destroy_images(game);
	if (game->winmlx)
		mlx_destroy_window(game->initmlx, game->winmlx);
	mlx_destroy_display(game->initmlx);
	free(game->initmlx);
	ft_printf("\nExit DRACO Game\n");
	exit(0);
}

void	to_complete(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->floor.ptr, x
		* 32, y * 32);
	mlx_put_image_to_window(game->initmlx, game->winmlx, game->player.ptr, x
		* 32, y * 32);
}

void	errors_map(t_game *game)
{
	write(2, "Error: Map not supported\n", 25);
	ft_free(game->map);
	exit(EXIT_FAILURE);
}
