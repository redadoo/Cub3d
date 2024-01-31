/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:47:37 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/24 17:02:40 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	flag_sharp(const char *str, unsigned int j)
{
	int	lenght;

	str++;
	lenght = 0;
	if (*str == 'x' && j != 0)
		lenght += printstring("0x");
	if (*str == 'X' && j != 0)
		lenght += printstring("0X");
	if (j > 0 && j <= 9)
	{
		lenght += printchars(j + '0');
	}
	else
	{
		ft_put_hex(j, (char)*str);
		lenght += ft_len_hex(j);
	}
	return (lenght);
}

int	flag_space(const char *s, va_list ap)
{
	int	lenght;
	int	i;

	i = 0;
	lenght = 0;
	s++;
	if (*s == 's')
	{
		lenght += printstring(va_arg(ap, char *));
	}
	if (*s == 'd' || *s == 'i')
	{
		i = va_arg(ap, int);
		if (i >= 0)
			lenght += printchars(' ');
		lenght += printdigit(i);
	}
	return (lenght);
}

int	flag_plus(const char *s, va_list ap)
{
	int	lenght;
	int	i;

	i = 0;
	lenght = 0;
	s++;
	if (*s == 'd' || *s == 'i')
	{
		i = va_arg(ap, int);
		if (i >= 0)
			lenght += printchars('+');
		lenght += printdigit(i);
	}
	return (lenght);
}
