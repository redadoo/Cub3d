/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:10:50 by fborroto          #+#    #+#             */
/*   Updated: 2024/02/12 16:55:42 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

bool	valid_surroundings(char **map_part, size_t i, size_t j)
{
	return (is_onstr("01EWNS", map_part[i - 1][j - 1]) && is_onstr("01EWNS",
			map_part[i - 1][j]) && is_onstr("01EWNS", map_part[i - 1][j + 1])
		&& is_onstr("01EWNS", map_part[i][j - 1]) && is_onstr("01EWNS",
			map_part[i][j + 1]) && is_onstr("01EWNS", map_part[i + 1][j - 1])
		&& is_onstr("01EWNS", map_part[i + 1][j]) && is_onstr("01EWNS",
			map_part[i + 1][j + 1]));
}

/**
 * @brief Checks if the elements in the map have valid surroundings.
 *
 * @param map_part A 2D array of characters representing a part of the map.
 * @return true if the elements have valid surroundings, false otherwise.
 */
static bool	valid_elements(char **map_part)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map_part[i + 1])
	{
		j = 1;
		while (map_part[i][j] && j < last_idx(map_part[i - 1])
			&& j < last_idx(map_part[i + 1]))
		{
			if (is_onstr("0EWNS", map_part[i][j])
				&& !valid_surroundings(map_part, i, j))
				return (false);
			j += 1;
		}
		while (map_part[i][j])
		{
			if (map_part[i][j] != '1')
				return (false);
			j += 1;
		}
		i += 1;
	}
	return (true);
}

/**
 * @brief Checks if the player position is valid in the map.
 *
 * @param map A 2D array of characters representing the map.
 * @return true if the player position is valid, false otherwise.
 */
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

/**
 * @brief Checks if the map has valid walls surrounding it.
 *
 * @param map A 2D array of characters representing the map.
 * @return true if the walls surrounding are valid, false otherwise.
 */
static	bool	wall_surrounding(char **map)
{
	int	i;
	int	j;

	j = -1;
	while (map[0][++j])
		if (!is_onstr(" 1", map[0][j]))
			return (false);
	j = -1;
	i = matrix_height(map) - 1;
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
			return (false);
		j = last_idx(map[i]) - 1;
		if (map[i][j] != '1')
			return (false);
	}
	return (true);
}

bool	parse_map(char **map)
{
	if (!wall_surrounding(map) || !valid_elements(map) || !player_position(map))
		return (false);
	return (true);
}
