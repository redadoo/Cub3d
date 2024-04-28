/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:50:16 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/28 16:20:50 by edoardo          ###   ########.fr       */
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

char	**readfile(char *file)
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

bool	readmap(t_game *game, char *filename)
{
	char	**file_content;
	char	**info_texture;
	char	**map;

	if (!check_file(filename))
		return (false);
	file_content = readfile(filename);
	info_texture = read_texture(file_content);
	if (get_info_texture(&game->assets, info_texture))
	{
		map = get_map_part(file_content);
		if (map == NULL || map[0] == NULL || !parse_map(map))
		{
			free_matrix(map);
			return (free_matrix(file_content), false);
		}
		else
			game->map = map;
	}
	return (free_matrix(file_content), true);
}
