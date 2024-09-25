/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 08:15:40 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/27 08:17:10 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char const *s, char c)
{
	int	tot_w;

	tot_w = 0;
	while (*s)
	{
		if (*s != c)
		{
			tot_w++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (tot_w);
}

static char	*ft_word_dup(const char *start, int len)
{
	char	*word;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (len--)
		word[len] = start[len];
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**ret;
	int			i;
	int			words;
	const char	*start;

	i = 0;
	words = ft_count_word(s, c);
	ret = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		if (s > start)
			ret[i++] = ft_word_dup(start, s - start);
	}
	ret[i] = NULL;
	return (ret);
}
