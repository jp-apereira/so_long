/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaopereira <joaopereira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:51:17 by joaopereira       #+#    #+#             */
/*   Updated: 2023/08/24 16:59:08 by joaopereira      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *game, int key)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y - 1][x] == 'E' && game->collect_count == 0)
		exit_game(game);
	if (game->map[y - 1][x] == '1' || (game->map[y - 1][x] == 'E'
			&& game->collect_count != 0))
		return ;
	else if (game->map[y - 1][x] == 'C')
		game->collect_count--;
	refresh_graphics_player(game, x, y, 'w');
	game->map[y][x] = '0';
	game->map[y - 1][x] = 'P';
	game->player_y--;
	game->moves_count++;
	ft_printf("Moves: %d\n", game->moves_count);
}

void	move_s(t_game *game, int key)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y + 1][x] == '1' || (game->map[y + 1][x] == 'E'
			&& game->collect_count != 0))
		return ;
	if (game->map[y + 1][x] == 'E' && game->collect_count == 0)
		exit_game(game);
	else if (game->map[y + 1][x] == 'C')
		game->collect_count--;
	refresh_graphics_player(game, x, y, 's');
	game->map[y][x] = '0';
	game->map[y + 1][x] = 'P';
	game->player_y++;
	game->moves_count++;
	ft_printf("Moves: %d\n", game->moves_count);
}

void	move_a(t_game *game, int key)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x - 1] == '1' || game->map[y][x - 1] == 'E'
		&& game->collect_count != 0)
		return ;
	if (game->map[y][x - 1] == 'E' && game->collect_count == 0)
		exit_game(game);
	else if (game->map[y][x - 1] == 'C')
		game->collect_count--;
	refresh_graphics_player(game, x, y, 'a');
	game->map[y][x] = '0';
	game->map[y][x - 1] = 'P';
	game->player_x--;
	game->moves_count++;
	ft_printf("Moves: %d\n", game->moves_count);
}

void	move_d(t_game *game, int key)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (game->map[y][x + 1] == '1' || game->map[y][x + 1] == 'E'
		&& game->collect_count != 0)
		return ;
	if (game->map[y][x + 1] == 'E' && game->collect_count == 0)
		exit_game(game);
	else if (game->map[y][x + 1] == 'C')
		game->collect_count--;
	refresh_graphics_player(game, x, y, 'd');
	game->map[y][x] = '0';
	game->map[y][x + 1] = 'P';
	game->player_x++;
	game->moves_count++;
	ft_printf("Moves: %d\n", game->moves_count);
}

int	controls(int key, t_game *game)
{
	if (key == 65307)
		exit_game(game);
	if (key == 119)
		move_w(game, key);
	if (key == 115)
		move_s(game, key);
	if (key == 97)
		move_a(game, key);
	if (key == 100)
		move_d(game, key);
	return (1);
}
