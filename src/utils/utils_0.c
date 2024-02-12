/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:17:47 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 16:24:26 by edoardo          ###   ########.fr       */
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

void	free_matrix(char **matrix)
{
	int		i;
	char	*line;

	if (matrix == NULL)
		return ;
	i = 0;
	while (matrix[i])
	{
		line = matrix[i];
		if (line)
			free(line);
		line = NULL;
		i++;
	}
	free(matrix);
}

t_vector2_int	get_map_size(char **map)
{
	t_vector2_int	index;

	index.x = 0;
	index.y = 0;
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
