/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:06:39 by nfigueir          #+#    #+#             */
/*   Updated: 2024/05/21 10:10:02 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*backup;

	if (!(*del) || !lst || !*lst)
		return ;
	backup = *lst;
	while (*lst && lst)
	{
		*lst = backup->next;
		ft_lstdelone(backup, (*del));
		backup = *lst;
	}
}
