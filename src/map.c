/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:38:41 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/03 13:02:54 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*pick_all_map_item(t_game *game)
{
	char	*line;
	char	*buffer;
	char	*tmp;

	buffer = ft_strdup("");
	if (!buffer)
		return ((char *)ft_exit(game, MALLOC_ERROR, "in pick_all_map_item -> ft_strdup"));
	line = get_next_line(game->map->fd);
	while (line != NULL)
	{
		tmp = buffer;
		buffer = ft_strjoin(buffer, line);
		free(tmp);
		free(line);
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
	close(game->map->fd);
}
