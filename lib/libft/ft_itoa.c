/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:43:06 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/24 17:01:58 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*aus(int x, char *newstr, int i)
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

static char	*countdigit(int x, char *newstr)
{
	int		temp;
	int		i;

	temp = x;
	i = len(temp) + 1;
	newstr = aus(x, newstr, i);
	if (!newstr)
		return (NULL);
	i--;
	while (temp)
	{
		i--;
		if (temp % 10 >= 0)
			newstr[i] = temp % 10 + '0';
		else
			newstr[i] = temp % 10 * -1 + '0';
		temp /= 10;
	}
	return (newstr);
}

char	*ft_itoa(int temp)
{
	char	*newstr;

	newstr = NULL;
	newstr = countdigit(temp, newstr);
	if (newstr == NULL)
		return (NULL);
	if (temp < 0)
		newstr[0] = '-';
	return (newstr);
}
