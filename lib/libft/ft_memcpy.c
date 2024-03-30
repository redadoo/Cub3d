/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:48:37 by evocatur          #+#    #+#             */
/*   Updated: 2023/02/06 15:07:21 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*copy1;
	char			*copy2;
	unsigned int	i;

	copy1 = (char *)src;
	copy2 = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i != n)
	{
		copy2[i] = copy1[i];
		i++;
	}
	return (dst);
}
