/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:16:28 by evocatur          #+#    #+#             */
/*   Updated: 2023/11/24 16:47:54 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *backup, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!backup)
	{
		backup = (char *)malloc(1 * sizeof(char));
		backup[0] = '\0';
	}
	if (!backup || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(backup) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (backup)
		while (backup[++i] != '\0')
			str[i] = backup[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(backup) + ft_strlen(buff)] = '\0';
	free(backup);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_backup(char *backup)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (backup[i])
		str[j++] = backup[i++];
	str[j] = '\0';
	free(backup);
	return (str);
}

char	*ft_get_line(char *backup)
{
	int		i;
	char	*str;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		str[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		str[i] = backup[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
