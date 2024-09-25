/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 07:21:06 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/16 08:03:14 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

//int	main(void)
//{
//	char	src[10] = "123456789";
//	char	dst[5];
//	size_t	len;
//	
//	len = ft_strlcpy(dst, src, sizeof(dst));
//	printf("strinf dst: %s\n suposto a copiar: %zu", dst, len);
//}
