/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:50:21 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/01 14:33:12 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>

// ENUM
enum	e_error
{
	MALLOC_ERROR = -20,
};
enum	e_game
{
	SUCCESS	= 10,
	LOOSE	= 20,
	QUIT	= 30
};

typedef struct s_map
{
	int	fd;
}		t_map;


typedef struct s_game
{
	t_map	*map;
}t_game;

void	*ft_exit(t_game *game, int status, char *msg);

#endif
