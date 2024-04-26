/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:36:41 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/26 13:53:42 by edoardo          ###   ########.fr       */
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

bool	get_texture_path(char *coord, char **map, t_assets *assets)
{
	size_t	i;
	char	**tmp;

	i = 0;
	while (i < 6)
	{
		tmp = ft_split(map[i], ' ');
		if (streq(coord, tmp[0]))
		{
			if (matrix_height(tmp) != 2)
				return (free_matrix(tmp), false);
			put_info(assets, tmp[0], tmp[1]);
			return (free_matrix(tmp), true);
		}
		i += 1;
		free_matrix(tmp);
	}
	return (free_matrix(tmp), false);
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

bool	get_color(char *identifier, char **map, t_assets *assets)
{
	int		i;
	bool	res;
	char	**tmp;
	char	**rgb;

	i = -1;
	res = true;
	tmp = NULL;
	while (++i < 6)
	{
		free_matrix(tmp);
		tmp = ft_split(map[i], ' ');
		if (streq(identifier, tmp[0]))
		{
			if (matrix_height(tmp) != 2)
				res = false;
			rgb = ft_split(tmp[1], ',');
			if (res == true && !assign_rgb(rgb, assets, identifier))
				res = false;
			free_matrix(rgb);
			return (free_matrix(tmp), res);
		}
	}
	return (free_matrix(tmp), false);
}

bool	get_info_texture(t_assets *assets, char **textures_part)
{
	int		i;
	char	*coord[6];

	if (textures_part == NULL)
		return (false);
	i = 0;
	coord[0] = "NO";
	coord[1] = "SO";
	coord[2] = "EA";
	coord[3] = "WE";
	coord[4] = "F";
	coord[5] = "C";
	while (i < 6)
	{
		if (i > 3 && !get_color(coord[i], textures_part, assets))
			return (free_matrix(textures_part), false);
		else if (!get_texture_path(coord[i], textures_part, assets))
			return (free_matrix(textures_part), false);
		i++;
	}
	return (free_matrix(textures_part), true);
}
