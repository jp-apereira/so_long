/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalves-p <jalves-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 10:07:42 by jalves-p          #+#    #+#             */
/*   Updated: 2023/08/14 14:48:27 by jalves-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"

// int	main(int ac, char **av)
// {
// 	t_game	draco;

// 	check_ac(ac);
// }

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
 
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;
 
int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d \n", keysym);
	return (0);
}
 
int main(void)
{
	t_data data;
 
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "DRACO");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
 
	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
 
	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}