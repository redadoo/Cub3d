/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:20:48 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/24 17:02:26 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*src2;
	char			*dst2;

	src2 = (char *)src;
	dst2 = (char *)dst;
	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		src2 = src2 + n - 1;
		dst2 = dst2 + n - 1;
		while (n--)
			*dst2-- = *src2--;
	}
	else if (src >= dst)
	{
		while (n--)
			*dst2++ = *src2++;
	}
	return (dst);
}
