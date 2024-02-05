/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:36:41 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/05 20:32:17 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static bool	streq(char *str1, char *str2)
{
	size_t	i;

	if ((str1 && !str2) || (!str1 && str2))
		return (false);
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (false);
		i += 1;
	}
	return (true);
}

static void	put_info(t_map *map, char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str1[0] != '\n' && str1 && str2)
	{
		if (ft_strstr(str1, "NO"))
			map->n_wall.path = ft_strdup(str2);
		else if (ft_strstr(str1, "SO"))
			map->s_wall.path = ft_strdup(str2);
		else if (ft_strstr(str1, "WE"))
			map->e_wall.path = ft_strdup(str2);
		else if (ft_strstr(str1, "EA"))
			map->e_wall.path = ft_strdup(str2);
	}
}

static bool	parse_coord(char *coord, char **map, t_map *game_map)
{
	size_t	i;
	char	**temp;

	i = 0;
	while (i < 6)
	{
		temp = ft_split(map[i], ' ');
		if (streq(coord, temp[0]))
		{
			if (matrix_lenght(temp) != 2)
			{
				free_matrix(temp);
				return (false);
			}
			put_info(game_map, temp[0], temp[1]);
			return (true);
		}
		i += 1;
		free_matrix(temp);
	}
	return (false);
}


static bool	is_all_digits(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i += 1;
	}
	return (true);
}
static bool	fits_in_intrange(int n, int lowest, int highest)
{
	return (n >= lowest && n <= highest);
}

static bool	assign_rgb(char **rgb, t_map *game_map)
{
	size_t	i;
	int element_rgb[3];

	i = 0;
	if (matrix_lenght(rgb) != 3)
		return (false);
	while (rgb[i])
	{
		if (!is_all_digits(rgb[i]))
			return (false);
		element_rgb[i] = ft_atoi(rgb[i]);
		if (!fits_in_intrange(element_rgb[i], 0, 255))
			return (false);
		i += 1;
	}
	game_map->celin_color.x = element_rgb[0];
	game_map->celin_color.y = element_rgb[1];
	game_map->celin_color.z = element_rgb[2];
	return (true);
}

static bool	parse_rgb(char *identifier, char **map, t_map *game_map)
{
	int		i;
	bool	return_value;
	char	**temp;
	char	**rgb;

	i = -1;
	return_value = true;
	
	while (++i < 6)
	{
		temp = ft_split(map[i], ' ');
		if (streq(identifier, temp[0]))
		{
			if (matrix_lenght(temp) != 2)
				return_value = false;
			rgb = ft_split(temp[1], ',');
			if (return_value == true && !assign_rgb(rgb, game_map))
				return_value = false;
			free_matrix(rgb);
			free_matrix(temp);
			return (return_value);
		}
		free_matrix(temp);
	}	
	return (false);
}

bool	parse_textures(t_map *map, char **textures_part)
{
	bool	return_value;

	return_value = false;
	if (parse_coord("NO", textures_part, map) && parse_coord("SO", textures_part, map)
		&& parse_coord("EA", textures_part, map) && parse_coord("WE", textures_part, map)
		&& parse_rgb("C", textures_part, map) && parse_rgb("F", textures_part, map))
		return_value = true;
	free_matrix(textures_part);
	return (return_value);
}
