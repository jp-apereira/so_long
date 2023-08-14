#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "GetNextLine/get_next_line.h"
# include "Printf/ft_printf.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// typedef struct s_data
// {
// 	void	*ptr;
// 	char	*addr;
// 	int		bpp;
// 	int		line_length;
// 	int		x;
// 	int		y;
// 	int		endian;
// }			t_data;

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
} t_data;

typedef struct s_game
{
	char	**map;
	int		map_width;
	int		map_height;

	int		nmr_moves;
	int		nmr_collectibles;
	int		nmr_exit;
	int		nmr_player;

	t_data	img;
	t_data	wall;
	t_data	player_w;
	t_data	player_a;
	t_data	player_s;
	t_data	player_d;
	t_data	exit;
	t_data	exit2;
	t_data	collect;
	t_data	floor;

	int		p_x;
	int		p_y;

	int		ex_x;
	int		ex_y;

	void	*initmlx;
	void	*winmlx;

}			t_game;



/*         U T I L S          */

void	ft_free(char **map);
int		read_map(t_game *game, char *file);
void	render_game(t_data *data, t_game *game);
void	refresh_graphics(t_game *game, int old_x, int old_y, char direction);


/*         C O N T R O L S          */

int		controls(int key, t_game *game);
void	move_d(t_game *game, int key);
void	move_s(t_game *game, int key);
void	move_w(t_game *game, int key);
void	move_a(t_game *game, int key);



/*         I M A G S          */



/*         C H E C K E R S          */

int	exit_game(t_game *game);


/*         S O  L O N G         */

int	main(int argc, char **argv);


#endif