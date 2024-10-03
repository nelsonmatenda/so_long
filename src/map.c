/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:38:41 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/03 10:13:32 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*pick_all_map_item(t_game *game)
{
	char	*line;
	char	*buffer;

	buffer = ft_strdup("");
	line = get_next_line(game->map->fd);
	while (line != NULL)
	{
		buffer = ft_strjoin(buffer, line);
		line = get_next_line(game->map->fd);
	}
	return (buffer);
}

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
