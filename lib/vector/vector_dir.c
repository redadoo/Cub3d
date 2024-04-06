/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:49:27 by codespace         #+#    #+#             */
/*   Updated: 2024/04/06 15:36:10 by edoardo          ###   ########.fr       */
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

t_vector2	vector2_normalize(t_vector2 vec)
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

t_vector2_int	vector2_int_direction(t_vector2_int a, t_vector2_int b)
{
	t_vector2_int	dir;

	dir.x = a.x - b.x;
	dir.y = a.y - b.y;
	return (dir);
}

t_vector2_int	vector2_int_normalize(t_vector2_int vec)
{
	t_vector2_int	normalized_vec;

	normalized_vec.x = int_sign(vec.x);
	normalized_vec.y = int_sign(vec.y);
	return (normalized_vec);
}
