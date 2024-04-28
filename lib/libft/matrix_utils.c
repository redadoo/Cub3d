/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:10:53 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/28 01:25:59 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_matrix(char **matrix)
{
	int		i;
	char	*line;

	if (matrix == NULL)
		return ;
	i = 0;
	while (matrix[i])
	{
		line = matrix[i];
		safe_free(line);
		line = NULL;
		i++;
	}
	free(matrix);
}

size_t	matrix_height(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i += 1;
	return (i);
}

size_t	matrix_width(char **matrix)
{
	size_t	i;
	size_t	y;
	size_t	res;

	i = 0;
	y = 0;
	res = 0;
	if (!matrix)
		return (0);
	while (matrix[y])
	{
		while (matrix[y][i])
			i++;
		if (i > res)
			res = i;
		i = 0;
		y++;
	}
	return (res);
}

void	print_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}
