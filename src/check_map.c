/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:54:27 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/10 12:07:18 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_element_on_map(t_game *game, char c, t_vector pos)
{
	if (is_border(game, pos) && c != '1')
		ft_exit(game, MAP_ERR, "Not surrounded bay Wall");
	if (c == 'E')
		game->map->xc++;
	else if (c == 'P')
	{
		game->player->pos.y = pos.y;
		game->player->pos.x = pos.x;
		game->map->spawn.y = pos.y;
		game->map->spawn.x = pos.x;
		game->map->pc++;
	}
	else if (c == 'C')
		game->map->cc++;
	else if (c != '1' && c != '0')
		ft_exit(game, MAP_ERR, "You use invalid element in map.");
}

int	ft_fulfill(t_game *game, char **map, int x, int y)
{
	int	i;

	i = -1;
	if (x < 0 || y < 0 || x >= game->map->size->x || y >= game->map->size->y)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'E')
	{
		map[y][x] = 'V';
		return (0);
	}
	map[y][x] = 'V';
	while (++i < 4)
		if (ft_fulfill(game, map, \
			x + game->moves[i][1], y + game->moves[i][0]))
			return (1);
	return (0);
}

int	path_finder(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->size->y)
	{
		x = 0;
		while ((x < game->map->size->x) && map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	is_solvable(t_game *game)
{
	char	**map;

	map = ft_copy_matrix(game->map->item);
	if (!map)
		ft_exit(game, MALLOC_ERROR, "check_map.c > is_solvable()");
	ft_fulfill(game, map, game->player->pos.x, game->player->pos.y);
	if (!path_finder(game, map))
	{
		ft_free_matrix(map);
		ft_exit(game, MAP_ERR, "Map is not solvable.");
	}
	ft_free_matrix(map);
}

void	check_map(t_game *game)
{
	t_vector	pos;

	pos.y = 0;
	while (game->map->item[pos.y])
	{
		pos.x = 0;
		while (game->map->item[pos.y][pos.x])
		{
			check_element_on_map(game, game->map->item[pos.y][pos.x], pos);
			pos.x++;
		}
		if (pos.x != game->map->size->x)
			ft_exit(game, MAP_ERR, "The map must be rectagle");
		pos.y++;
	}
	if (game->map->xc != 1)
		ft_exit(game, MAP_ERR, "tips:number of exit. One exit(E) per map");
	if (game->map->pc != 1)
		ft_exit(game, MAP_ERR, "tips:number of player. One player(P) per map");
	if (game->map->cc < 1)
		ft_exit(game, MAP_ERR, "tips:Need at least one collectible(C)");
	is_solvable(game);
}
