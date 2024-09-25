/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:14:18 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/15 13:14:50 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

//int main(void)
//{
//	char buffer[10];
//	int		i;
//
//	i = 0;
//	bzero(buffer, sizeof(char)*10);
//	while(buffer[i])
//	{
//		printf("%c", buffer[i]);
//		i++;
//	}
//	puts("");
//}
