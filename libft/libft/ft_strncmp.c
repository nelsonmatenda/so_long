/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:51:23 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/21 22:10:59 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

//int main()
//{
//	char *s1 = "asdfgh";
//	char *s2 = "asd6fgh";
//	int t = ft_strncmp(s1, s2, 3);
//	printf("retorno:%d\n", t);
//	if (t == 0) 
//		printf("sim");
//	else
//		printf("nao");
//	return 0;
//}
