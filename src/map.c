/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:38:41 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/13 22:27:00 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	read_all_file(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line || !*line)
			break ;
		free(line);
	}
}

static char	*pick_all_map_item(t_game *game)
{
	char	*line;
	char	*buffer;
	char	*tmp;

	buffer = ft_strdup("");
	if (!buffer)
		return (
			ft_exit(game, MALLOC_ERROR, "pick_all_map_item -> ft_strdup"));
	line = get_next_line(game->map->fd);
	while (line != NULL)
	{
		tmp = buffer;
		if (*line == '\n')
			return (free(buffer), free(line), read_all_file(game->map->fd),
				ft_exit(game, FILE_ERROR, "Invalid Map"));
		buffer = ft_strjoin(buffer, line);
		if (!buffer)
			return (free(tmp), free(line), read_all_file(game->map->fd),
				ft_exit(game, MALLOC_ERROR,
					"in pick_all_map_item -> ft_strjoin"));
		free(tmp);
		free(line);
		line = get_next_line(game->map->fd);
	}
	return (buffer);
}

static void	check_extension_map(t_game *game, char *path_map)
{
	int	i;

	i = ft_strlen(path_map) - 5;
	if (i < 0)
		ft_exit(game, EXTENSION, "Try > <file>.ber");
	if (ft_strncmp((path_map + (i + 1)), \
		FILE_EXTENSION, ft_strlen(FILE_EXTENSION)))
		ft_exit(game, EXTENSION, "Try > <file>.ber");
}

int	matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

void	get_map(t_game *game, char *path_map)
{
	char	*buffer;

	check_extension_map(game, path_map);
	game->map->fd = open(path_map, O_RDONLY);
	if (game->map->fd == -1)
		ft_exit(game, FILE_ERROR, "in get_map");
	buffer = pick_all_map_item(game);
	game->map->item = ft_split(buffer, '\n');
	free(buffer);
	if (!game->map->item || !*game->map->item)
		ft_exit(game, MAP_ERR, "Nothing inside the map");
	game->map->size->x = ft_strlen(game->map->item[0]);
	game->map->size->y = matrix_size(game->map->item);
	close(game->map->fd);
}
