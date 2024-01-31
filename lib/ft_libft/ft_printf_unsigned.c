/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:10:29 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/24 17:05:35 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*aus(unsigned int x, char *newstr, int i)
{
	if (x == 0)
	{
		newstr = (char *)malloc(2 * sizeof(char));
		if (!newstr)
			return (NULL);
		newstr[0] = 0 + '0';
		newstr[i] = 0;
	}
	if (x != 0)
	{
		newstr = (char *)malloc(i * sizeof(char));
		if (!newstr)
			return (NULL);
		i--;
		newstr[i] = 0;
	}
	return (newstr);
}

static char	*countdigit(unsigned int x, char *newstr)
{
	unsigned int		temp;
	int					i;

	temp = x;
	i = len(temp) + 1;
	newstr = aus(x, newstr, i);
	if (!newstr)
		return (NULL);
	i--;
	while (temp)
	{
		i--;
		if (temp % 10 > 0)
			newstr[i] = temp % 10 + '0';
		else
			newstr[i] = temp % 10 * -1 + '0';
		temp /= 10;
	}
	return (newstr);
}

char	*ft_uitoa(unsigned int temp)
{
	char	*newstr;

	newstr = NULL;
	newstr = countdigit(temp, newstr);
	if (newstr == NULL)
		return (NULL);
	return (newstr);
}

int	convertunsigned(int n)
{
	int				i;
	unsigned int	j;
	char			*s;

	if (n >= 0)
	{
		i = printdigit(n);
		return (i);
	}
	if (n < 0)
	{
		j = n;
		s = ft_uitoa(j);
		i = printstring(s);
		free(s);
		return (i);
	}
	return (0);
}
