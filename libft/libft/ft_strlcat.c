/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 08:04:29 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/21 18:10:18 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

//int	main(void)
//{
//	char dst[10] = "123";
//	char src[11] = "4567891011";
//	size_t i = ft_strlcat(dst, src, sizeof(dst));
//	printf("dst: %s\nreturn: %zu\n", dst, i);
//	//i = strlcat(dst, src, sizeof(dst));
//	//printf("dst: %s\nreturn: %zu\n", dst, i);
//	return (0);
//}
