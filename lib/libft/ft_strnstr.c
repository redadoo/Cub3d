/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:18:32 by evocatur          #+#    #+#             */
/*   Updated: 2023/06/09 13:21:01 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare(const char *x, const char *y)
{
	while (*x && *y)
	{
		if (*x != *y)
			return (0);
		x++;
		y++;
	}
	return (*y == '\0');
}

const char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (*needle == '\0' || needle == NULL)
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

const char	*ft_strstr(const char *x, const char *y)
{
	while (*x != '\0')
	{
		if ((*x == *y) && compare(x, y))
			return (x);
		x++;
	}
	return (NULL);
}
