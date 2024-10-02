/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:25:41 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/02 13:36:55 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_map	*init_s_map(t_game *game)
{
	t_map	*map;
	map = (t_map *)malloc(sizeof(t_map) * 1);
	if (!map)
		return ((t_game *)ft_exit(game, MALLOC_ERROR, "in init_s_map"));
	map->fd = -1;
	map->item = NULL;
}

static t_game	*init_s_game(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game) * 1);
	if (!game)
		return ((t_game *)ft_exit(game, MALLOC_ERROR, "in init_s_game"));
	game->map = NULL;
	return (game);
}

t_game	*ft_init(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game) * 1);
	if (!game)
		return (ft_exit(game, MALLOC_ERROR, "in init_game"));
	game = init_s_game();
	game->map = init_s_map(game);
	return (game);
}
