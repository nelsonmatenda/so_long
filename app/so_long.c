/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:40:29 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/11 15:25:40 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	window_close(t_game *game)
{
	return (*(int *)ft_exit(game, QUIT, "This game is too easy, try again"));
}

int	hook_close(t_game *game)
{
	mlx_hook(game->win.ptr, 17, 0, window_close, game);
	mlx_hook(game->win.ptr, 2, 1L << 0, key_press, game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;
	(void)av;
	if (ac != 2)
		return (*(int *)ft_exit(NULL, MAP_ERR, "Theres no maps: Try > ./so_long maps/default.ber"));
	game = ft_init_struct_game();
	get_map(game, av[1]);
	check_map(game);
	init_mlx(game);
	init_sprites(game);
	hook_close(game);
	render(game);
	mlx_loop(game->mlx);
	return (*(int *)ft_exit(game, SUCCESS, "Great Job"));
}
