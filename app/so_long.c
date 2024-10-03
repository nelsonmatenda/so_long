/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:40:29 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/03 11:33:49 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;
	(void)av;
	if (ac != 2)
		return (*(int *)ft_exit(NULL, NO_MAPS, "Theres no maps: Try > ./so_long maps/default.ber"));
	game = ft_init_struct_game();
	get_map(game, av[1]);
	int i = -1;
	while(game->map->item[++i])
	{
		printf("%s", game->map->item[i]);
		puts("");
	}
	return (0);
}
