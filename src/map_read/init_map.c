/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:36:41 by edoardo           #+#    #+#             */
/*   Updated: 2024/01/31 15:15:26 by edoardo          ###   ########.fr       */
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
			map->n_wall.path = ft_strdup(parse_info(str));
		else if (ft_strstr(str, "SO"))
			map->s_wall.path = ft_strdup(parse_info(str));
		else if (ft_strstr(str, "WE"))
			map->e_wall.path = ft_strdup(parse_info(str));
		else if (ft_strstr(str, "EA"))
			map->e_wall.path = ft_strdup(parse_info(str));
		else if (ft_strstr(str, "F"))
			map->floor_color = string_to_vector((char *)ft_strstr(str, " "));
		else if (ft_strstr(str, "C"))
			map->celin_color = string_to_vector((char *)ft_strstr(str, " "));
	}
}

int load_texture(t_game *game)
{
}
