/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:37:00 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/13 22:31:51 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_s_map(t_game *game)
{
	if (game->map->item)
		ft_free_matrix(game->map->item);
	if (game->map->size)
		free(game->map->size);
	game->map->item = NULL;
	free(game->map);
	game->map = NULL;
}

static void	free_s_player(t_game *game)
{
	if (game->player->sprite.img)
		mlx_destroy_image(game->mlx, game->player->sprite.img);
	free(game->player);
}

static void	free_s_texture(t_game *game)
{
	if (game->tex->coin.img)
		mlx_destroy_image(game->mlx, game->tex->coin.img);
	if (game->tex->exit.img)
		mlx_destroy_image(game->mlx, game->tex->exit.img);
	if (game->tex->floor.img)
		mlx_destroy_image(game->mlx, game->tex->floor.img);
	if (game->tex->wall.img)
		mlx_destroy_image(game->mlx, game->tex->wall.img);
	free(game->tex);
	game->tex = NULL;
}

void	ft_free(t_game *game)
{
	if (game->map)
		free_s_map(game);
	if (game->player)
		free_s_player(game);
	if (game->tex)
		free_s_texture(game);
	if (game->mlx)
	{
		if (game->win.ptr)
			mlx_destroy_window(game->mlx, game->win.ptr);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	game = NULL;
}
