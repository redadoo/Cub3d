/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:49:27 by codespace         #+#    #+#             */
/*   Updated: 2024/04/06 14:31:33 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector2	vector2_direction(t_vector2 a, t_vector2 b)
{
	t_vector2	dir;

	dir.x = a.x - b.x;
	dir.y = a.y - b.y;
	return (dir);
}

double	magnitude(t_vector2 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}

t_vector2	normalize(t_vector2 vec)
{
	double		mag;
	t_vector2	normalized_vec;

	mag = magnitude(vec);
	if (mag != 0)
	{
		normalized_vec.x = vec.x / mag;
		normalized_vec.y = vec.y / mag;
	}
	else
	{
		normalized_vec.x = 0;
		normalized_vec.y = 0;
	}
	return (normalized_vec);
}
