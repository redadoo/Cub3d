/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:34:36 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/10 14:56:05 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	check_dir(char ch)
{
	if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
		return (1);
	return (0);
}

bool	fits_in_int_range(int n, int lowest, int highest)
{
	return (n >= lowest && n <= highest);
}

t_vector2_int	get_map_size(char **map)
{
	t_vector2_int	index;

	set_vector2_int(&index,0,0);
	while (map[index.y])
	{
		index.x = 0;
		while (map[index.y][index.x])
		{
			index.x++;
		}
		index.y++;
	}
	return (index);
}
