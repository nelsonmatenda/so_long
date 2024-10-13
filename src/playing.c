/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:37:40 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/13 22:24:06 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_valid_move(t_game *game, char **map, int x, int y)
{
	return (x >= 0
		&& x < game->map->size->x
		&& y >= 0
		&& y < game->map->size->y
		&& map[y][x] != '1');
}

static void	player_move(t_game *game, int y, int x)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->player->pos.x;
	prev_y = game->player->pos.y;
	if (game->map->item[y][x] == EXIT && game->map->cc == 0)
	{
		ft_printf("%d\n", ++game->player->moves);
		ft_exit(game, SUCCESS, NULL);
	}
	else if (is_valid_move(game, game->map->item, x, y) \
	&& game->map->item[y][x] != EXIT)
	{
		game->map->item[prev_y][prev_x] = FLOOR;
		if (game->map->item[y][x] == COIN)
			game->map->cc--;
		game->player->pos.x = x;
		game->player->pos.y = y;
		game->map->item[y][x] = PLAYER;
		ft_printf("%d\n", ++game->player->moves);
	}
	render(game);
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_Q || key == KEY_ESC)
		return (window_close(game));
	if (key == KEY_W || key == KEY_TOP)
		player_move(game, game->player->pos.y - 1, game->player->pos.x);
	if (key == KEY_S || key == KEY_BOT)
		player_move(game, game->player->pos.y + 1, game->player->pos.x);
	if (key == KEY_A || key == KEY_LEFT)
		player_move(game, game->player->pos.y, game->player->pos.x - 1);
	if (key == KEY_D || key == KEY_RIGHT)
		player_move(game, game->player->pos.y, game->player->pos.x + 1);
	return (0);
}
