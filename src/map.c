/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:38:41 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/02 14:08:02 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char

void	get_map(t_game *game, char *path_map)
{
	char	*buffer;

	game->map->fd = open(path_map, O_RDONLY);
	if (game->map->fd == -1)
		ft_exit(game, FD_ERROR, "in get_map");
	buffer = pick_all_map_item(game);
	game->map->item = ft_split(buffer, '\n');
	free(buffer);
}
