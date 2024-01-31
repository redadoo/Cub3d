/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:30:25 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/24 17:02:56 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_hex(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, char c)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, c);
		ft_put_hex(num % 16, c);
	}
	else
	{
		if (num <= 9)
		{
			if ((c == 'X') && num + '0' >= 'a' && num + '0' <= 'z')
				printchars((num + '0') - 32);
			else
				printchars((num + '0'));
		}
		else
		{
			if ((c == 'X') && num - 10 + 'a' >= 'a' && num - 10 + 'a' <= 'z')
				printchars((num - 10 + 'a') - 32);
			else
				printchars((num - 10 + 'a'));
		}
	}
}

int	printhex(const char *str, va_list ap)
{
	unsigned long long	j;

	j = va_arg(ap, unsigned);
	if (j > 0 && j <= 9)
	{
		return (printchars(j + '0'));
	}
	else
	{
		ft_put_hex(j, (char)*str);
	}
	return (ft_len_hex(j));
}
