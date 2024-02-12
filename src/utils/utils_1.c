/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:34:36 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 14:00:22 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	set_vector3_int(t_vector3_int *v, int x, int y, int z)
{
	v->x = x;
	v->z = z;
	v->y = y;
}

void	set_vector3(t_vector3 *v, double x, double y, double z)
{
	v->x = x;
	v->z = z;
	v->y = y;
}

void	set_vector2(t_vector2 *v, double x, double y)
{
	v->x = x;
	v->y = y;
}

size_t	matrix_lenght(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i += 1;
	return (i);
}
