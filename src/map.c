/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:38:41 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/03 15:21:48 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*pick_all_map_item(t_game *game)
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
		if (!buffer)
			return (free(tmp), free(line), (char *)ft_exit(game, MALLOC_ERROR, "in pick_all_map_item -> ft_strjoin"));
		free(tmp);
		free(line);
		line = get_next_line(game->map->fd);
	}
	return (buffer);
}

static void	check_extension_map(t_game *game, char *path_map)
{
	int	i;

	i = ft_strlen(path_map) - 4;
	if (i < 0)
		ft_exit(game, EXTENSION, "Try > <file>.ber");
	if (ft_strncmp((path_map + i), FILE_EXTENSION, ft_strlen(FILE_EXTENSION)))
		ft_exit(game, EXTENSION, "Try > <file>.ber");
}

void	get_map(t_game *game, char *path_map)
{
	char	*buffer;

	check_extension_map(game, path_map);
	game->map->fd = open(path_map, O_RDONLY);
	if (game->map->fd == -1)
		ft_exit(game, FD_ERROR, "in get_map");
	buffer = pick_all_map_item(game);
	game->map->item = ft_split(buffer, '\n');
	free(buffer);
	close(game->map->fd);
}
