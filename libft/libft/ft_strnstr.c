/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:36:55 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/21 18:17:30 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*s2)
		return ((char *)s1);
	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n && s1[i])
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s2[j] && i + j < n && s1[i + j] == s2[j])
				j++;
			if (!s2[j])
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char s1[] = "assim que encontrar que retorna para mim";
	char *s2 = "que";
	char *found = ft_strnstr(s1, s2, sizeof(s1));
	printf("achou: %s\n", found);
	return (0);
}*/
