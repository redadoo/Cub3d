/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:36:41 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/03 17:56:02 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	put_info(t_assets *assets, char *str1, char *str2)
{
	if (str1[0] != '\n' && str1 && str2)
	{
		if (ft_strstr(str1, "NO"))
			assets->n_wall.path = ft_strdup(str2);
		else if (ft_strstr(str1, "SO"))
			assets->s_wall.path = ft_strdup(str2);
		else if (ft_strstr(str1, "WE"))
			assets->w_wall.path = ft_strdup(str2);
		else if (ft_strstr(str1, "EA"))
			assets->e_wall.path = ft_strdup(str2);
	}
}

bool	parse_coord(char *coord, char **map, t_assets *assets)
{
	size_t	i;
	char	**temp;

	i = 0;
	while (i < 6)
	{
		temp = ft_split(map[i], ' ');
		if (streq(coord, temp[0]))
		{
			if (matrix_height(temp) != 2)
			{
				free_matrix(temp);
				return (false);
			}
			put_info(assets, temp[0], temp[1]);
			free_matrix(temp);
			return (true);
		}
		i += 1;
		free_matrix(temp);
	}
	free_matrix(temp);
	return (false);
}

bool	assign_rgb(char **rgb, t_assets *assets, char *identifier)
{
	size_t	i;
	int		element_rgb[3];

	i = 0;
	if (matrix_height(rgb) != 3)
		return (false);
	while (rgb[i])
	{
		if (!is_all_digits(rgb[i]))
			return (false);
		element_rgb[i] = ft_atoi(rgb[i]);
		if (!fits_in_int_range(element_rgb[i], 0, 255))
			return (false);
		i += 1;
	}
	if (streq(identifier, "C"))
		set_vector3_int(&assets->celin_color, element_rgb[0], element_rgb[1],
			element_rgb[2]);
	else
		set_vector3_int(&assets->floor_color, element_rgb[0], element_rgb[1],
			element_rgb[2]);
	return (true);
}

bool	parse_rgb(char *identifier, char **map, t_assets *assets)
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
			if (matrix_height(temp) != 2)
				return_value = false;
			rgb = ft_split(temp[1], ',');
			if (return_value == true && !assign_rgb(rgb, assets, identifier))
				return_value = false;
			free_matrix(rgb);
			free_matrix(temp);
			return (return_value);
		}
		free_matrix(temp);
	}
	free_matrix(temp);
	return (false);
}

bool	parse_textures(t_assets *assets, char **textures_part)
{
	bool	return_value;

	if (textures_part == NULL)
		return (false);
	return_value = false;
	for(int i = 0; textures_part[i]; i++)
	{
		printf("%s\n",textures_part[i]);
	}
	if (parse_coord("NO", textures_part, assets) && parse_coord("SO",
			textures_part, assets) && parse_coord("EA", textures_part, assets)
		&& parse_coord("WE", textures_part, assets) && parse_rgb("C",
			textures_part, assets) && parse_rgb("F", textures_part, assets))
		return_value = true;
	free_matrix(textures_part);
	return (return_value);
}
