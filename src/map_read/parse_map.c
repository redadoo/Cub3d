/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 00:10:50 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/26 17:58:04 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

bool	valid_surroundings(char **map_part, t_vector2_int ind)
{
	if (ft_strchr("01EWNS", map_part[ind.x - 1][ind.y - 1]) == NULL || ft_strchr("01EWNS", map_part[ind.x - 1][ind.y]) == NULL)
		return (false);
	if (ft_strchr("01EWNS", map_part[ind.x - 1][ind.y + 1]) == NULL || ft_strchr("01EWNS", map_part[ind.x][ind.y - 1]) == NULL)
		return (false);
	if (ft_strchr("01EWNS", map_part[ind.x][ind.y + 1]) == NULL || ft_strchr("01EWNS", map_part[ind.x + 1][ind.y - 1]) == NULL)
		return (false);
	if (ft_strchr("01EWNS", map_part[ind.x + 1][ind.y]) == NULL || ft_strchr("01EWNS", map_part[ind.x + 1][ind.y + 1])== NULL)
		return (false);
	return (true);

}

/**
 * @brief Checks if the elements in the map have valid surroundings.
 *
 * @param map_part A 2D array of characters representing a part of the map.
 * @return true if the elements have valid surroundings, false otherwise.
 */
static bool	valid_elements(char **map_part)
{
	t_vector2_int ind;

	ind.x = 1;
	while (map_part[ind.x + 1])
	{
		ind.y = 1;
		while (map_part[ind.x][ind.y] && ind.y < last_idx(map_part[ind.x - 1])
			&& ind.y < last_idx(map_part[ind.x + 1]))
		{
			if (ft_strchr("0EWNS", map_part[ind.x][ind.y]) != NULL
				&& !valid_surroundings(map_part, ind))
				return (false);
			ind.y++;
		}
		ind.x++;
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
			if (ft_strchr("NSWE", map[i][j]) != NULL)
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
static bool	wall_surrounding(char **map)
{
	t_vector2_int i;

	set_vector2_int(&i,-1,-1);
	while (map[0][++i.y])
		if (ft_strchr(" 1", map[0][i.y]) == NULL)
			return (false);
	set_vector2_int(&i, matrix_height(map) - 1, -1);
	while (map[i.x][++i.y])
		if (ft_strchr(" 1", map[i.x][i.y]) == NULL)
			return (false);
	i.x = -1;
	while (map[++i.x])
	{
		i.y = 0;
		while (is_spaces(map[i.x][i.y]))
			i.y += 1;
		if (map[i.x][i.y] != '1')
			return (false);
		i.y = last_idx(map[i.x]) - 1;
		if (map[i.x][i.y] != '1')
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
