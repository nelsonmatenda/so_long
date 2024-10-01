/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:25:41 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/01 14:32:40 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game	*ft_init(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game) * 1);
	if (!game)
		return (ft_exit(game, MALLOC_ERROR, "in init_game"));
	return (game);
}
