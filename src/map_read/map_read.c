/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:50:16 by evocatur          #+#    #+#             */
/*   Updated: 2024/03/31 15:47:25 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int	file_lines_count(char *file_name)
{
	int		i;
	int		file_fd;
	char	*line;

	i = 0;
	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
		return (0);
	line = get_next_line(file_fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(file_fd);
	}
	close(file_fd);
	return (i);
}

static char	**get_full_map(char *file_name)
{
	int		scene_fd;
	char	**full_map;
	int		map_len;
	int		i;

	i = 0;
	scene_fd = open(file_name, O_RDONLY);
	if (scene_fd == -1)
		return (NULL);
	map_len = file_lines_count(file_name);
	if (!map_len)
	{
		close(scene_fd);
		return (NULL);
	}
	full_map = (char **)malloc(sizeof(char *) * (map_len + 1));
	if (!full_map)
		return (NULL);
	full_map[map_len] = NULL;
	while (i < map_len)
	{
		full_map[i] = trim_free(get_next_line(scene_fd), "\n");
		i++;
	}
	return (close(scene_fd), full_map);
}

/* static void	print_mat(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		printf("%s acap\n", tmp[i]);
		i++;
	}
} */

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
