/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:04:33 by nfigueir          #+#    #+#             */
/*   Updated: 2024/10/13 22:25:44 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_free_matrix_with_indice(char **matrix, int i)
{
	while (i > 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
}

int	ft_get_matrix_size(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}

char	**ft_copy_matrix(char **matrix)
{
	char	**new_matrix;
	int		y;

	if (!matrix)
		return (NULL);
	new_matrix = malloc(sizeof(char *) * (ft_get_matrix_size(matrix) + 1));
	if (!new_matrix)
		return (NULL);
	y = 0;
	while (matrix && matrix[y])
	{
		new_matrix[y] = ft_strdup(matrix[y]);
		if (!new_matrix[y])
			return (ft_free_matrix_with_indice(new_matrix, y), NULL);
		y++;
	}
	new_matrix[y] = NULL;
	return (new_matrix);
}

t_img	init_s_img(void)
{
	t_img	img;

	img.addr = NULL;
	img.img = NULL;
	img.bits_per_pixel = 0;
	img.endian = 0;
	img.size.x = 0;
	img.size.y = 0;
	img.size_line = 0;
	return (img);
}
