/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:14:04 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/09 15:17:55 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_border(t_game *game, t_vector pos)
{
	if (pos.y == 0 || pos.x == 0
		|| pos.y == (game->map->size->y - 1)
		|| pos.x == (game->map->size->x - 1))
		return (1);
	return (0);
}
