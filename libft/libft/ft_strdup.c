/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 23:12:29 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/19 23:48:34 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	new = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}

/*int main()
{
	char s[] = "fui duplicado";
	char *dup = ft_strdup(s);
	printf("%s\n%p\n%p\n%p", dup, dup, &dup, s);
}*/
