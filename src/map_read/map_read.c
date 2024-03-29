/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:50:16 by evocatur          #+#    #+#             */
/*   Updated: 2024/03/26 17:16:25 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

bool	is_scene_empty(char *file_name)
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

char	**get_textures_part(int scene_fd)
{
	size_t	i;
	char	*line;
	char	**scene;

	scene = malloc((6 + 1) * sizeof(char *));
	printf("%p\n", scene);
	i = 0;
	while (i < 6)
	{
		line = trim_free(get_next_line(scene_fd), "\n");
		if (line == NULL)
		{
			free(scene);
			return (NULL);
		}
		if (only_spaces(line))
		{
			free(line);
			continue ;
		}
		scene[i] = line;
		i += 1;
	}
	scene[i] = NULL;
	free(get_next_line(scene_fd));
	return (scene);
}

int	get_nbr_map_lines(char *file_name)
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
		if (line == NULL)
			return (-1);
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

char	**get_map_part(char *file_name, int scene_fd)
{
	int		i;
	int		nbr_lines;
	char	**map;
	char	*line;
	int		check;

	check = 1;
	nbr_lines = get_nbr_map_lines(file_name);
	if (nbr_lines == -1)
		return (NULL);
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
		if (!check)
			line = trim_free(get_next_line(scene_fd), "\n");
		map[i] = line;
		check = 0;
	}
	return (map);
}

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
	if (!parse_textures(&game->assets, textures_part))
		return_value = false;
	if (return_value != false)
	{
		map_part = get_map_part(file_name, scene_fd);
		if (map_part == NULL || !parse_map(map_part))
		{
			free_matrix(map_part);
			return_value = false;
		}
	}
	if (return_value != false)
		game->map = map_part;
	close(scene_fd);
	return (return_value);
}
