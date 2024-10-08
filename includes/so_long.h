/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:50:21 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/08 12:18:59 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/include/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h> // TODO: deletar no final do projecto! usado para testar

# define FILE_EXTENSION ".ber"

// ENUM
enum	e_error
{
	MALLOC_ERROR	= -20,
	MAP_ERR			= -21,
	FILE_ERROR		= -22,
	EXTENSION		= -23
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
}		t_map;


typedef struct s_game
{
	t_map	*map;
}t_game;

void	ft_free(t_game *game);
void	*ft_exit(t_game *game, int status, char *msg);
t_game	*ft_init_struct_game(void);
void	get_map(t_game *game, char *path_map);
#endif
