/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:21:18 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/05 16:20:27 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	check_extension(char *file)
{
	int		count;
	char	*tmp;

	count = 4;
	tmp = (char *)ft_strstr(file, ".cub");
	if (tmp == NULL)
		return (1);
	while (count)
	{
		tmp++;
		count--;
	}
	if ((int)*tmp != 0)
		return (1);
	count = open(file, O_RDONLY);
	if (count == -1)
		return (1);
	close(count);
	return (0);
}

size_t	last_idx(char *map_line)
{
	size_t	i;

	i = ft_strlen(map_line) - 1;
	while (is_spaces(map_line[i]))
		i -= 1;
	i += 1;
	return (i);
}
