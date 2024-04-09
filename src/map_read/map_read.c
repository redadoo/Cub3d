/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:50:16 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/09 16:33:24 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	file_lines_count(char *file)
{
	char	c;	
	int		fd;	
	int		linecount;
	int		readcount;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (true)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

char	**get_full_map(char *file)
{
	int				i;
	int				fd;
	char			**map;

	map = ft_calloc((sizeof(char *)), file_lines_count(file) + 1);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < file_lines_count(file))
	{
		map[i] = get_next_line(fd);
		map[i] = trim_free(map[i], "\n");
		i++;
	}
	close(fd);
	return (map);
}

bool	readmap(t_game *game, char *file_name)
{
	char	**full_map;
	char	**textures_part;
	char	**map_part;
	bool	return_value;

	return_value = true;
	full_map = get_full_map(file_name);
	if (is_scene_empty(file_name))
		return (false);
	textures_part = get_textures_part(full_map);
	if (!parse_textures(&game->assets, textures_part))
		return_value = false;
	if (return_value != false)
	{
		map_part = get_map_part(full_map);
		if (map_part == NULL || !parse_map(map_part))
		{
			free_matrix(map_part);
			return_value = false;
		}
	}
	if (return_value != false)
		game->map = map_part;
	free_matrix(full_map);
	return (return_value);
}
