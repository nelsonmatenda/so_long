/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 07:21:36 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/15 10:30:41 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = (unsigned char)c;
		i++;
	}
	return (s);
}

/*int main(void)
{
	char buffer[10];
	int		i;

	i = 0;
	ft_memset(buffer, 'b', sizeof(char)*10);
	while(buffer[i])
	{
		printf("%c", buffer[i]);
		i++;
	}
	puts("");
}*/
