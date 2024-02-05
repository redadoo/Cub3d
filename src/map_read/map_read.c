/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:50:16 by evocatur          #+#    #+#             */
/*   Updated: 2024/02/05 20:27:27 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static bool	is_scene_empty(char *file_name)
{
	bool	return_value;
	char	*temp;
	int		scene_fd;

	return_value = false;
	scene_fd = open(file_name, O_RDONLY);
	if (!scene_fd)
		return (false);
	temp = get_next_line(scene_fd);
	if (temp == NULL)
		return_value = true;
	free(temp);
	close(scene_fd);
	return (return_value);
}

static char	**get_textures_part(int scene_fd)
{
	char	**scene;
	size_t	i;
	char	*line;

	scene = malloc((6 + 1) * sizeof(char *));
	i = 0;
	while (i < 6)
	{
		line = trim_free(get_next_line(scene_fd), "\n");
		if (only_spaces(line))
		{
			free(line);
			continue ;
		}
		scene[i] = line;
		i += 1;
	}
	scene[i] = NULL;
	print_matrix(scene);
	free(get_next_line(scene_fd));
	return (scene);
}

static size_t	get_nbr_map_lines(char *file_name)
{
	int		scene_fd;
	size_t	i;
	size_t	count;
	char	*line;

	scene_fd = open(file_name, O_RDONLY);
	i = 0;
	count = 0;
	line = get_next_line(scene_fd);
	while (i < 6)
	{
		free(line);
		line = get_next_line(scene_fd);
		if (!only_spaces(line))
			i += 1;
	}
	while (line)
	{
		if (!only_spaces(line))
			count += 1;
		free(line);
		line = get_next_line(scene_fd);
	}
	close(scene_fd);
	return (count);
}

static char	**get_map_part(char *file_name, int scene_fd)
{
	size_t	i;
	size_t	nbr_lines;
	char	**map;
	char	*line;
	int		check;

	check = 1;
	nbr_lines = get_nbr_map_lines(file_name);
	map = ft_calloc(sizeof(char *), (nbr_lines + 1));
	i = -1;
	line = trim_free(get_next_line(scene_fd), "\n");
	while (line && !line[0])
	{
		free(line);
		line = trim_free(get_next_line(scene_fd), "\n");
	}
	while (++i < nbr_lines)
	{
		if(!check)
			line = trim_free(get_next_line(scene_fd), "\n");
		map[i] = line;
		printf("%s\n",line);
		check = 0;
	}
	return (map);
}

/* read a file and return the map inside it*/
bool	readmap(t_game *game, char *file_name)
{
	bool	return_value;
	int		scene_fd;
	char	**textures_part;
	char	**map_part;

	return_value = true;
	scene_fd = open(file_name, O_RDONLY);
	if (scene_fd == -1 || is_scene_empty(file_name))
		return (false);
	textures_part = get_textures_part(scene_fd);
	if (!parse_textures(&game->map, textures_part))
		return_value = false;
	if (return_value != false)
	{
		map_part = get_map_part(file_name, scene_fd);
		if (!parse_map(map_part))
		{
			free_matrix(map_part);
			return_value = false;
		}
	}
	if (return_value != false)
		game->map.matrix = map_part;
	close(scene_fd);
	return (return_value);
}

void	free_matrix(char **map)
{
	int		i;
	char	*line;

	i = 0;
	while (map[i])
	{
		line = map[i];
		if (line)
			free(line);
		i++;
	}
	free(map);
}
