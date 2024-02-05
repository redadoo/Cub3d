/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:10:50 by fborroto          #+#    #+#             */
/*   Updated: 2024/02/05 20:17:36 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

size_t	matrix_lenght(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i += 1;
	return (i);
}

static size_t	last_idx(char *map_line)
{
	size_t	i;

	i = ft_strlen(map_line) - 1;
	while (is_spaces(map_line[i]))
		i -= 1;
	i += 1;
	return (i);
}

bool	valid_surroundings(char **map_part, size_t i, size_t j)
{
	return (is_onstr("01EWNS", map_part[i - 1][j - 1]) && is_onstr("01EWNS",
			map_part[i - 1][j]) && is_onstr("01EWNS", map_part[i - 1][j + 1])
		&& is_onstr("01EWNS", map_part[i][j - 1]) && is_onstr("01EWNS",
			map_part[i][j + 1]) && is_onstr("01EWNS", map_part[i + 1][j - 1])
		&& is_onstr("01EWNS", map_part[i + 1][j]) && is_onstr("01EWNS",
			map_part[i + 1][j + 1]));
}

static bool	valid_elements(char **map_part)
{
	size_t i;
	size_t j;

	i = 1;
	while (map_part[i + 1])
	{
		j = 1;
		while (map_part[i][j] && j < last_idx(map_part[i - 1])
			&& j < last_idx(map_part[i + 1]))
		{
			if (is_onstr("0EWNS", map_part[i][j])
				&& !valid_surroundings(map_part, i, j))
				return (printf("qua2 : |%c|\n", map_part[i][j]),false);
			j += 1;
		}
		while (map_part[i][j])
		{
			if (map_part[i][j] != '1')
				return (printf("qua1 : |%c|\n", map_part[i][j]),false);
			j += 1;
		}
		i += 1;
	}
	return (true);
}

static bool	player_position(char **map)
{
	bool	player_found;
	int		i;
	int		j;

	player_found = false;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_onstr("NSWE", map[i][j]))
			{
				if (player_found == true)
					return (false);
				else
					player_found = true;
			}
		}
	}
	return (player_found);
}

static bool	wall_surrounding(char **map)
{
	int	i;
	int	j;

	j = -1;
	while (map[0][++j])
		if (!is_onstr(" 1", map[0][j]))
			return (printf("qua1 : |%c|\n", map[0][j]), false);
	j = -1;
	i = matrix_lenght(map) - 1;
	while (map[i][++j])
		if (!is_onstr(" 1", map[i][j]))
			return (false);
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (is_spaces(map[i][j]))
			j += 1;
		if (map[i][j] != '1')
			return (printf("qua3\n"),false);
		j = last_idx(map[i]) - 1;
		if (map[i][j] != '1')
			return (printf("qua4\n"),false);
	}
	return (true);
}

bool	parse_map(char **map)
{
	if (!wall_surrounding(map) || !valid_elements(map)
		|| !player_position(map))
        return (false);
	return (true);
}