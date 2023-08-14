/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-p <jalves-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:07:24 by jalves-p          #+#    #+#             */
/*   Updated: 2023/08/14 16:28:14 by jalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	read_map(t_game *game, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
	}
	close(fd);	
	if (game->map)
		game->map_width = ft_strlen(game->map[0]) - 1;
	return (1);
}

void	render_game(t_data *data, t_game *game)
{
	int		y;
	int		x;
	char	currentElement;
	t_data	*texture;
	int		render_x;
	int		render_y;

	int TILE_SIZE = 32; // Tamanho de cada célula do mapa
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			currentElement = game->map[y][x];
			render_x = x * TILE_SIZE;
			render_y = y * TILE_SIZE;
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, texture->mlx_ptr,
				render_x, render_y);
			x++;
		}
		y++;
	}
	mlx_loop(data->mlx_ptr);
}

void	refresh_graphics(t_game *game, int old_x, int old_y,
		char direction)
{
	// Atualize a imagem da nova posição da personagem com base na direção do movimento
	t_data *player_texture = NULL;

	if (direction == 'w')
		player_texture = &game->player_w;
	else if (direction == 'a')
		player_texture = &game->player_a;
	else if (direction == 's')
		player_texture = &game->player_s;
	else if (direction == 'd')
		player_texture = &game->player_d;

	int TILE_SIZE = 32; // Tamanho de cada célula do mapa
	int new_x = game->p_x * TILE_SIZE;
	int new_y = game->p_y * TILE_SIZE;

	// Limpe a posição antiga da personagem no mapa
	mlx_clear_window(game->initmlx, game->winmlx);

	// Renderize a nova posição da personagem
	mlx_put_image_to_window(game->initmlx, game->winmlx, player_texture->mlx_ptr,
		new_x, new_y);

	// Atualize a janela
	mlx_loop(game->initmlx);
}
