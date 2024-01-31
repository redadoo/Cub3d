/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:17:29 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/24 22:17:16 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_statstr(int fd, char *statstr)
{
	char	*str;
	int		bytes;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(statstr, '\n') && bytes != 0)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(str);
			return (NULL);
		}
		str[bytes] = '\0';
		statstr = ft_strjoin(statstr, str);
	}
	free(str);
	return (statstr);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*statstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	statstr = ft_statstr(fd, statstr);
	if (!statstr)
		return (NULL);
	str = ft_get_line(statstr);
	statstr = ft_backup(statstr);
	return (str);
}
