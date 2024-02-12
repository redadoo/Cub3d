/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:17:47 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 13:55:51 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	check_dir(char ch)
{
	if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
		return (1);
	return (0);
}

void	print_matrix(char **matrix, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '1')
				printf("\033[0;36m%c", matrix[i][j]);
			else if (matrix[i][j] == '0')
				printf("\033[0;37m%c", matrix[i][j]);
			else
				printf("\033[0;31m%c", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	printf("%d %d\n", i, j);
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
