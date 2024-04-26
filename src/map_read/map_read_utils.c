/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:29:27 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/26 13:02:58 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

bool	check_file(char *namefile)
{
	int		fd;
	char	*tmp;
	int		bytes_rd;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	fd = open(namefile, O_RDONLY);
	if (!fd)
		return (false);
	bytes_rd = read(fd, tmp, BUFFER_SIZE);
	if (bytes_rd == -1 || bytes_rd == 0)
	{
		close(fd);
		safe_free(tmp);
		return (false);
	}
	safe_free(tmp);
	close(fd);
	if (tmp == NULL)
		return(false);
	return (true);
}

char	**read_texture(char **full_map)
{
	t_vector2_int	i;
	char			**scene;

	scene = malloc(7 * sizeof(char *));
	if (!scene)
		return (NULL);
	set_vector2_int(&i, 0, -1);
	while (i.x < 6)
	{
		if (full_map[++i.y] == NULL)
			return (free_matrix(scene), NULL);
		if (only_spaces(full_map[i.y]))
			continue ;
		scene[i.x] = ft_strdup(full_map[i.y]);
		i.x++;
	}
	scene[i.x] = NULL;
	return (scene);
}

int	file_linecount(char **full_map)
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
		count++;
		j++;
	}
	return (count);
}

char	**get_map_part(char **full_map)
{
	int		i;
	int		j;
	int		file_line;
	char	**map;

	j = 0;
	file_line = file_linecount(full_map);
	if (file_line == -1)
		return (NULL);
	map = ft_calloc(sizeof(char *), (file_line + 1));
	i = 0;
	while (i < 6)
	{
		if (!only_spaces(full_map[j]))
			i++;
		j++;
	}
	i = 0;
	while (full_map[j] && only_spaces(full_map[j]))
		j++;
	while (full_map[j])
	{
		printf("-%s\n", full_map[j]);
		map[i++] = ft_strdup(full_map[j]);
		j++;
	}
	return (map);
}
