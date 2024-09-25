/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:41:47 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/21 17:27:15 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		chr;

	i = 0;
	chr = (char)c;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)(s + i));
		i++;
	}
	if (chr == '\0')
		return ((char *)(s + i));
	return (NULL);
}

//int	main()
//{
//	char tweet[] = "This is my @men@tion";
//	char *mention = ft_strchr(tweet, '@');
//	printf("mention: %s\n", mention);
//	return (0);
//}
