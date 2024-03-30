/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:47:37 by evocatur          #+#    #+#             */
/*   Updated: 2023/05/18 15:31:18 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printstring(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (*s)
	{
		i += (int)write(1, s, 1);
		s++;
	}
	return (i);
}

int	printchars(int c)
{
	char	i;

	i = (char)c;
	return (write(1, &i, 1));
}

int	printdigit(int n)
{
	int		i;
	char	*s;

	s = ft_itoa(n);
	i = printstring(s);
	free(s);
	return (i);
}
