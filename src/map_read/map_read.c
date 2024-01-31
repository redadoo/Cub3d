/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:50:16 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/29 17:17:33 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static	int	map_height(char *file)
{
	char	*str;	
	int		fd;	
	int		linecount;
	int		readcount;
	int		is_map;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	str = get_next_line(fd);
	while (str)
	{
		if (str[0] == '1')
			linecount++;
		str = get_next_line(fd);
	}
	close(fd);
	printf("%d\n",linecount);
	return (linecount - 1);
}

int	file_linecount(char *file)
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
		{
			break ;
		}
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

/* read a file and return the map inside it*/
t_map	readmap(char *file)
{
	int				fd;
	char			*str;
	char			**map;
	t_vector2_int	index;
	t_map			game_map;

/* 	printf("%d\n",  map_height(file));
 */	map = ft_calloc((sizeof(char *)), map_height(file) + 1);
	if (map == NULL)
		return (game_map);
	fd = open(file, O_RDONLY);
	index.x = -1;
	index.y = -1;
	while (++index.x < file_linecount(file))
	{
		str = get_next_line(fd);
		if (str[0] == '1')
			map[++index.y] = ft_strdup(str);
		else
			extract_info(&game_map, str);
		free(str);
	}
	game_map.map = map;
	close(fd);
	return (game_map);
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
