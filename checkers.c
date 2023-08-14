/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-p <jalves-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:07:12 by jalves-p          #+#    #+#             */
/*   Updated: 2023/08/14 16:43:48 by jalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	// Verifique se o jogador coletou todos os colecionáveis e chegou à saída
	if (game->nmr_collectibles == 0 && game->p_x == game->ex_x
		&& game->p_y == game->ex_y)
		return 1; // Jogador venceu
	else
    return 0;
}

void error(int ac, char **av)
{
  if(ac != 2)
  {
    write(1, "Not the right number of args\n", 30);
    exit;
  }
}