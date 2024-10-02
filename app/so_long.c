/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:40:29 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/02 11:10:56 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
		return (*(int *)ft_exit(NULL, NO_MAPS, "Theres no maps: Try > ./so_long maps/default.ber"));
	return (0);
}
