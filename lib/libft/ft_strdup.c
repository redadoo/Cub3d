/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:07:24 by evocatur          #+#    #+#             */
/*   Updated: 2023/02/03 14:42:28 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*newstr;

	i = 0;
	while (s[i])
		i++;
	i++;
	newstr = (char *)malloc(i * sizeof(char));
	if (newstr == NULL)
		return ((char *) NULL);
	ft_memcpy(newstr, s, i);
	return (newstr);
}
