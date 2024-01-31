/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:52:42 by evocatur          #+#    #+#             */
/*   Updated: 2023/02/07 17:47:16 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*newstr;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		newstr = (char *)malloc(1 + i * sizeof(char));
		if (!newstr)
			return (NULL);
		i = 0;
		while (s[i])
		{
			newstr[i] = f(i, s[i]);
			i++;
		}
		newstr[i++] = '\0';
		return (newstr);
	}
	return (NULL);
}
