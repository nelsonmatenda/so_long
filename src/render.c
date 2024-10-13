/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:12:55 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/13 15:18:01 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_sprite(t_game *game, t_img sprite, int line, int column)
{
	int	x;
	int	y;

	x = column * sprite.size.x;
	y = line * sprite.size.y;
	mlx_put_image_to_window(game->mlx, game->win.ptr, sprite.img, x, y);
}

void	print_sprite(t_game *game, int y, int x)
{
	char img;

	img = game->map->item[y][x];
	if (img == WALL)
		render_sprite(game, game->tex->wall, y, x);
	else if (img == FLOOR)
		render_sprite(game, game->tex->floor, y, x);
	else if (img == COIN)
		render_sprite(game, game->tex->coin, y, x);
	else if (img == EXIT)
		render_sprite(game, game->tex->exit, y, x);
	else if (img == PLAYER)
		render_sprite(game, game->player->sprite, y, x);
}

int	render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->size->y)
	{
		x = 0;
		while (x < game->map->size->x)
		{
			print_sprite(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
