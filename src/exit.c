/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:34:36 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/13 22:29:22 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_msg(int error, char *msg_error)
{
	if (error == MALLOC_ERROR)
		ft_printf("\033[1;31mError\n=>\033[0m Memory allocation failed.\n");
	if (error == EXTENSION)
		ft_printf("\033[1;31mError\n=>\033[0m Invalid file extension.\n");
	if (error == FILE_ERROR)
		ft_printf("\033[1;31mError\n=>\033[0m Failed to open file.\n");
	if (error == MAP_ERR)
		ft_printf("\033[1;31mError\n=>\033[0m Something wrong with map.\n");
	if (error == MLX_ERR)
		ft_printf("\033[1;31mError\n=>\033[0m Lib MLX failed.\n");
	if (error == SPT_ERR)
		ft_printf("\033[1;31mError\n=>\033[0m Sprites not found.\n");
	if (msg_error)
		ft_printf("\033[90m%s\033[0m\n", msg_error);
}

void	success_msg(int status)
{
	if (status == SUCCESS)
		ft_printf("\033[0;32mSuccess:\033[0m You won the game!\033[0m\n");
	if (status == LOOSE)
		ft_printf("\033[1;33mYou loose the game\n\033[0m");
	if (status == QUIT)
		ft_printf("\033[1;33mNotice:\033[0m \
		Player has exited the game.\033[0m\n");
}

void	*ft_exit(t_game *game, int status, char *msg)
{
	if (game)
		ft_free(game);
	if (status < 0)
	{
		error_msg(status, msg);
		return (exit(EXIT_FAILURE), (void *)EXIT_FAILURE);
	}
	else
		success_msg(status);
	return (exit(EXIT_SUCCESS), (void *)EXIT_SUCCESS);
}
