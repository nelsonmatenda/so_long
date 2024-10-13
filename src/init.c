/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:25:41 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/09 15:11:10 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_map	*init_s_map(t_game *game)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (!map)
		return ((t_map *)ft_exit(game, MALLOC_ERROR, "in init_s_map"));
	map->size =  (t_vector *)malloc(sizeof(t_vector));
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
	game->player = (t_player *)malloc(sizeof(t_player));
	if (!game->player)
		ft_exit(game, MALLOC_ERROR, "init.c > init_s_player()");
	game->player->pos.x = 0;
	game->player->pos.y = 0;
	game->player->sprite.img = NULL;
}

static t_game	*init_s_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game) * 1);
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
	return (game);
}
void	init_s_texture(t_game *game)
{
	game->tex = (t_textures *)malloc(sizeof(t_textures));
	if (!game->tex)
		ft_exit(game, MALLOC_ERROR, "in init_s_texture");
	game->tex->coin.img = NULL;
	game->tex->exit.img = NULL;
	game->tex->floor.img = NULL;
	game->tex->wall.img = NULL;
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
