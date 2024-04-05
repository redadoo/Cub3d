/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:20:20 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/05 16:42:10 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (true);
	return (false);
}

bool	only_spaces(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!is_spaces(str[i]))
			return (false);
		i += 1;
	}
	return (true);
}
