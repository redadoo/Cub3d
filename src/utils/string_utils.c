/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:21:18 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/28 14:09:36 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	f_ind(char *map_line)
{
	int	i;

	i = ft_strlen(map_line) - 1;
	while (map_line[i] && is_spaces(map_line[i]))
		i--;
	i++;
	return (i);
}

void	remove_character(char *from, const char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (from[i])
	{
		if (!strchr(set, from[i]))
			from[j++] = from[i];
		i++;
	}
	from[j] = 0;
}
