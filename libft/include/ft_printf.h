/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:01:27 by nfigueir          #+#    #+#             */
/*   Updated: 2024/06/05 15:01:28 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int	ft_putchar(char c);
int	ft_putnbr(int nbr);
int	ft_putstr(char *str);
int	putnbr_u(unsigned int nbr);
int	put_pointer(void *nbr, char *base);
int	put_hex(unsigned int nbr, char *base);
int	ft_printf(const char	*format, ...);

#endif