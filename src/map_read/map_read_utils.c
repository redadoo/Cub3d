/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:29:27 by fborroto          #+#    #+#             */
/*   Updated: 2024/03/31 16:56:57 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

bool	is_scene_empty(char *file_name)
{
	bool	return_value;
	char	*temp;
	int		scene_fd;
	int		bytes_rd;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	return_value = false;
	scene_fd = open(file_name, O_RDONLY);
	if (!scene_fd)
		return (false);
	bytes_rd = read(scene_fd, temp, BUFFER_SIZE);
	if (bytes_rd == -1 || bytes_rd == 0)
	{
		free(temp);
		return (NULL);
	}
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
		scene[i] = ft_strdup(full_map[j]);
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

	i = 0;
	j = 0;
	count = 0;
	while (i < 6)
	{
		if (full_map[j] == NULL)
			return (-1);
		if (!only_spaces(full_map[j]))
			i++;
		j++;
	}
	while (full_map[j])
	{
		if (!only_spaces(full_map[j]))
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

	j = 0;
	nbr_lines = get_nbr_map_lines(full_map);
	if (nbr_lines == -1)
		return (NULL);
	map = ft_calloc(sizeof(char *), (nbr_lines + 1));
	i = 0;
	while (i < 6)
	{
		if (!only_spaces(full_map[j]))
			i++;
		j++;
	}
	i = 0;
	while (full_map[j])
	{
		if (!only_spaces(full_map[j]))
			map[i++] = ft_strdup(full_map[j]);
		j++;
	}
	return (map);
}
