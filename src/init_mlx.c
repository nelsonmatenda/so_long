/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:35:29 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/10 13:20:21 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit(game, MLX_ERR, "Something with mlx_init()");
	game->win.ptr = mlx_new_window(game->mlx, \
		game->map->size->x * IMG_WID, game->map->size->y * IMG_HGHT, \
		TITLE);
	if (!game->win.ptr)
		ft_exit(game, MLX_ERR, "Something with mlx_new_window()");
	game->win.height = game->map->size->y * IMG_HGHT;
	game->win.width = game->map->size->x * IMG_WID;
	mlx_loop(game->mlx);
}
