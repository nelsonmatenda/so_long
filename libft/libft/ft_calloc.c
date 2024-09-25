/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 22:46:55 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/21 22:31:11 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0 && (size > (4294967296 / count)))
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

/*int	main()
{
#include <time.h>
	int size = 0;
	int *junk = 0;
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		size = rand() % 16000;
		junk = malloc(size * sizeof(int));
		for (int j = 0; j < size; j++)
			junk[j] = rand();
		free(junk);
	}
	int *array;
	array = ft_calloc(100, sizeof(int));
	for (int i = 0; i < 100; i++)
		printf("%d", array[i]);
	free(array);
	puts(" ");
	return 0;
}*/
