/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:37:00 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/03 12:01:46 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_map(t_game *game)
{
	int	i;

	i = -1;
	if (game->map->item)
	{
		while(game->map->item[++i])
			free(game->map->item[i]);
	}
	free(game->map->item);
	game->map->item = NULL;
	free(game->map);
	game->map = NULL;
}

void	ft_free(t_game *game)
{
	if (game->map)
		free_map(game);
	free(game);
	game = NULL;
}
