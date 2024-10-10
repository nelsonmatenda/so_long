/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:37:00 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/09 14:26:58 by nfigueir         ###   ########.fr       */
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
	if (game->player)
		free(game->player);
}
void	ft_free(t_game *game)
{
	if (game->map)
		free_s_map(game);
	if (game->player)
		free_s_player(game);
	free(game);
	game = NULL;
}
