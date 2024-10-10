/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:11:45 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/10 11:35:29 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(char **map)
{
	int y = 0;
	while(map[y])
	{
		int x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				printf("%c", map[y][x]);
			else
				printf("\033[1;31m%c\033[0m", map[y][x]);
			x++;
		}
		y++;
		printf("\n");
	}
}
