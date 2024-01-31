/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:36:41 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/30 16:14:47 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static char	*parse_info(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (i == 1 && *str >= 'a' && *str <= 'z')
			break ;
		if (*str == ' ')
			i = 1;
		str++;
	}
	return (str);
}

void	extract_info(t_map *map, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[0] != '\n' && str)
	{
		if (ft_strstr(str, "NO"))
			map->north_wall.path = ft_strdup(parse_info(str));
		else if (ft_strstr(str, "SO"))
			map->south_wall.path = ft_strdup(parse_info(str));
		else if (ft_strstr(str, "WE"))
			map->east_wall.path = ft_strdup(parse_info(str));
		else if (ft_strstr(str, "EA"))
			map->east_wall.path = ft_strdup(parse_info(str));
		else if (ft_strstr(str, "F"))
			map->floor_color = string_to_vector((char *)ft_strstr(str, " "));
		else if (ft_strstr(str, "C"))
			map->celin_color = string_to_vector((char *)ft_strstr(str, " "));
	}
}

int load_texture(t_game *game)
{
	game->map.north_wall.img = mlx_xpm_file_to_image(game->mlx, "./texture/wall/mossy.xpm",
		&game->map.north_wall.img_width, &game->map.north_wall.img_height);
	game->map.north_wall.pixels  = mlx_get_data_addr(game->map.north_wall.img, &game->map.north_wall.bits_per_pixel, &game->map.north_wall.line_size, &game->map.north_wall.endian);
	if (game->map.north_wall.img == NULL)
		return (0);
	game->map.south_wall.img = mlx_xpm_file_to_image(game->mlx, "./texture/wall/wood.xpm",
		&game->map.south_wall.img_width, &game->map.south_wall.img_height);
	game->map.south_wall.pixels  = mlx_get_data_addr(game->map.south_wall.img, &game->map.south_wall.bits_per_pixel, &game->map.south_wall.line_size, &game->map.south_wall.endian);
	if (game->map.south_wall.img == NULL)
		return (0);
	game->map.ovest_wall.img = mlx_xpm_file_to_image(game->mlx, "./texture/wall/redbrick.xpm",
		&game->map.ovest_wall.img_width, &game->map.ovest_wall.img_height);
	game->map.ovest_wall.pixels  = mlx_get_data_addr(game->map.ovest_wall.img, &game->map.ovest_wall.bits_per_pixel, &game->map.ovest_wall.line_size, &game->map.ovest_wall.endian);
	if (game->map.ovest_wall.img == NULL)
		return (0);
	game->map.east_wall.img = mlx_xpm_file_to_image(game->mlx, "./texture/wall/purplestone.xpm",
		&game->map.east_wall.img_width, &game->map.east_wall.img_height);
	game->map.east_wall.pixels  = mlx_get_data_addr(game->map.east_wall.img, &game->map.east_wall.bits_per_pixel, &game->map.east_wall.line_size, &game->map.east_wall.endian);
	if (game->map.east_wall.img == NULL)
		return (0);
	return (1);
}
