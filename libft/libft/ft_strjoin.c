/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:47:55 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/20 10:37:55 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
	{
		join[i] = *(s1 + j);
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		join[i] = *(s2 + j);
		i++;
		j++;
	}
	join[i] = 0;
	return (join);
}

//int main(int ac, char **av)
//{
//	if (ac > 1)
//		printf("foi joinado: %s", ft_strjoin(av[1], av[2]));
//	else
//	printf("2 arg");
//	return 0;
//}
