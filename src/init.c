/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:25:41 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/13 22:26:22 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_map	*init_s_map(t_game *game)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return ((t_map *)ft_exit(game, MALLOC_ERROR, "in init_s_map"));
	map->size = (t_vector *)ft_calloc(1, sizeof(t_vector));
	if (!map->size)
		return ((t_map *)ft_exit(game, MALLOC_ERROR, "in init_s_map"));
	map->fd = -1;
	map->size->x = 0;
	map->size->y = 0;
	map->item = NULL;
	map->ec = 0;
	map->wc = 0;
	map->cc = 0;
	map->xc = 0;
	map->pc = 0;
	return (map);
}

static void	init_s_player(t_game *game)
{
	game->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!game->player)
		ft_exit(game, MALLOC_ERROR, "init.c > init_s_player()");
	game->player->pos.x = 0;
	game->player->pos.y = 0;
	game->player->sprite.addr = NULL;
	game->player->sprite.size_line = 0;
	game->player->sprite.endian = 0;
	game->player->sprite.bits_per_pixel = 0;
	game->player->sprite.size.x = 0;
	game->player->sprite.size.y = 0;
	game->player->sprite.img = NULL;
	game->player->moves = 0;
}

static t_game	*init_s_game(void)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return ((t_game *)ft_exit(game, MALLOC_ERROR, "in init_s_game"));
	game->map = NULL;
	game->player = NULL;
	game->moves[0][0] = -1;
	game->moves[0][1] = 0;
	game->moves[1][0] = 1;
	game->moves[1][1] = 0;
	game->moves[2][0] = 0;
	game->moves[2][1] = -1;
	game->moves[3][0] = 0;
	game->moves[3][1] = 1;
	game->mlx = NULL;
	game->tex = NULL;
	game->win.ptr = NULL;
	game->win.height = 0;
	game->win.width = 0;
	return (game);
}

void	init_s_texture(t_game *game)
{
	game->tex = (t_textures *)ft_calloc(1, sizeof(t_textures));
	if (!game->tex)
		ft_exit(game, MALLOC_ERROR, "in init_s_texture");
	game->tex->coin = init_s_img();
	game->tex->exit = init_s_img();
	game->tex->floor = init_s_img();
	game->tex->wall = init_s_img();
}

t_game	*ft_init_struct_game(void)
{
	t_game	*game;

	game = init_s_game();
	game->map = init_s_map(game);
	init_s_player(game);
	init_s_texture(game);
	return (game);
}
