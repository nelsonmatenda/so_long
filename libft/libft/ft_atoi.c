/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:45:02 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/19 22:20:52 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (ft_isdigit(s[i]))
	{
		result = result * 10 + s[i] - '0';
		i++;
	}
	return (result * sign);
}

/*int	main(int ac, char **av)
{
	if (ac > 1)
	{
		printf("orifinal: %d\n", atoi(av[1]));
		printf("ft_atoi: %d\n", ft_atoi(av[1]));
	}
	return 0;
}*/
