/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:50:21 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/13 14:32:54 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/include/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h> // TODO: deletar no final do projecto! usado para testar

# define FILE_EXTENSION ".ber"
# define IMG_WID 32
# define IMG_HGHT 32
# define TITLE "so_long"
# define WALL_XPM "./textures/wall.xpm"
# define COIN_XPM "./textures/coin.xpm"
# define FLOOR_XPM "./textures/floor.xpm"
# define EXIT_XPM "./textures/exit.xpm"
# define PLAYER_XPM "./textures/player.xpm"

// MAP ITEM
# define WALL	'1'
# define COIN	'C'
# define EXIT	'E'
# define PLAYER	'P'
# define FLOOR	'0'

// KEY CODES
# define KEY_Q		113
# define KEY_ESC	65307
// ENUM
enum	e_error
{
	MALLOC_ERROR	= -20,
	MAP_ERR			= -21,
	FILE_ERROR		= -22,
	EXTENSION		= -23,
	MLX_ERR			= -24,
	SPT_ERR			= -25
};
enum	e_game
{
	SUCCESS	= 10,
	LOOSE	= 20,
	QUIT	= 30,
};

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	int			fd;
	char		**item;
	t_vector	*size;
	int			ec;
	int			wc;
	int			cc;
	int			xc;
	int			pc;
	t_vector	spawn;
}				t_map;

typedef struct s_win
{
	void	*ptr;
	int		height;
	int		width;
}			t_win;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			size_line;
	int			endian;
	int			bits_per_pixel;
	t_vector	size;
}				t_img;

typedef struct s_textures
{
	t_img	wall;
	t_img	floor;
	t_img	coin;
	t_img	exit;
}			t_textures;

typedef struct s_player
{
	t_vector	pos;
	t_img		sprite;
} t_player;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	int			moves[4][2];
	void		*mlx;
	t_win		win;
	t_textures	*tex;
}t_game;

void	print_map(char **map); //TODO: DELETAR NO FINAL

// ERROR HANDLER
void	ft_free(t_game *game);
void	*ft_exit(t_game *game, int status, char *msg);
void	ft_free_matrix_with_indice(char **matrix, int i);
void	ft_free_matrix(char **matrix);

// INIT GAME MAP AND CHECK MAP
t_game	*ft_init_struct_game(void);
void	get_map(t_game *game, char *path_map);
int		is_border(t_game *game, t_vector pos);
char	**ft_copy_matrix(char **matrix);
void	check_map(t_game *game);

// INIT MLX
void	init_mlx(t_game *game);
void	init_sprites(t_game *game);
int		key_press(int key, t_game *game);
int	window_close(t_game *game);

int	render(t_game *game);
#endif
