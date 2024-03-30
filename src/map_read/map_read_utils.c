/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:29:27 by fborroto          #+#    #+#             */
/*   Updated: 2024/03/30 17:28:04 by fborroto         ###   ########.fr       */
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

char	**get_textures_part(char **full_map)
{
	size_t	i;
	size_t	j;
	char	**scene;

	scene = malloc((6 + 1) * sizeof(char *));
	i = 0;
	j = -1;
	while (i < 6)
	{
		if (full_map[++j] == NULL)
		{
			free(scene);
			return (NULL);
		}
		if (only_spaces(full_map[j]))
			continue ;
		scene[i] = full_map[j];
		i++;
	}
	scene[i] = NULL;
	return (scene);
}

int	get_nbr_map_lines(char **full_map)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	*line;

	i = 0;
	j = 0;
	count = 0;
	while (i < 6)
	{
		if (full_map[j] == NULL)
			return (-1);
		if (!only_spaces(line))
			i++;
		j++;
	}
	while (full_map[j])
	{
		if (!only_spaces(line))
			count++;
		j++;
	}
	return (count);
}

char	**get_map_part(char **full_map)
{
	int		i;
	int		j;
	int		nbr_lines;
	char	**map;
	int		check;

	check = 1;
	j = 0;
	nbr_lines = get_nbr_map_lines(full_map);
	if (nbr_lines == -1)
		return (NULL);
	map = ft_calloc(sizeof(char *), (nbr_lines + 1));
	i = -1;
	while (full_map[j] && !full_map[j][0])
		j++;
	while (++i < nbr_lines)
	{
		map[i] = full_map[j];
		j++;
	}
	return (map);
}
