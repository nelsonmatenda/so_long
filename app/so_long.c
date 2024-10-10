/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:40:29 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/10 13:07:54 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	(void)av;
	if (ac != 2)
		return (*(int *)ft_exit(NULL, MAP_ERR, "Theres no maps: Try > ./so_long maps/default.ber"));
	game = ft_init_struct_game();
	get_map(game, av[1]);
	check_map(game);
	int i = -1;
	init_mlx(game);
	while(game->map->item[++i])
	{
		printf("%s", game->map->item[i]);
		puts("");
	}
	return (*(int *)ft_exit(game, SUCCESS, "OKAY"));
}
