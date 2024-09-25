/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:28:03 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/15 11:18:13 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

//int	main(void)
//{
//	char s[] = "abcdfghijklmnopqrstuvwxyz";
//	char d[27];
//
//	ft_memcpy(d, s, sizeof(char) * 27);
//	printf("d: %s\n", d);
//
//	char e[10];
//	memcpy(e, s+8, sizeof(char) * 9);
//	e[9]= '\0';
//
//	printf("e: %s\n", e);
//	return (0);
//}
