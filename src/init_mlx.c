/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:35:29 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/11 15:44:11 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_img	create_sprite(char *path, t_game *game)
{
	t_img	sprite;

	sprite.img = mlx_xpm_file_to_image(game->mlx, path, \
		&sprite.size.x, &sprite.size.y);
	if (sprite.img == NULL)
		ft_exit(game, MLX_ERR, path);
	sprite.addr = mlx_get_data_addr(sprite.img, \
		&sprite.bits_per_pixel, &sprite.size_line, &sprite.endian);
	return (sprite);
}

void	init_sprites(t_game *game)
{
	game->tex->wall = create_sprite(WALL_XPM, game);
	game->tex->coin = create_sprite(COIN_XPM, game);
	game->tex->floor = create_sprite(FLOOR_XPM, game);
	game->tex->exit = create_sprite(EXIT_XPM, game);
	game->player->sprite = create_sprite(PLAYER_XPM, game);
}

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
}
