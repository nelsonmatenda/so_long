/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:34:36 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/01 16:14:24 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_msg(int error, char *msg_error)
{
	if (error == MALLOC_ERROR)
		ft_printf("\033[1;31mError:\033[0m Memory allocation failed\n");
	if (msg_error)
		ft_printf("\033[90m%s\033[0m\n", msg_error);
}

void	sucess_msg(int status)
{
	if (status == SUCCESS)
		ft_printf("\033[0;32mSuccess: You won the game!\033[0m\n");
	if (status == LOOSE)
		ft_printf("You loose the game\n");
	if (status == QUIT)
		ft_printf("\033[1;33mNotice: A player has exited the game.\033[0m\n");
}

void	*ft_exit(t_game *game, int status, char *msg)
{
	if (game)
		//TODO: faça free do game todo.
	if (status < 0)
	{
		error_msg(status, msg);
		return (exit(EXIT_FAILURE), (void *)EXIT_FAILURE);
	}
	else
		success_msg(status);
	return (exit(EXIT_SUCCESS), (void *)EXIT_SUCCESS);
}
