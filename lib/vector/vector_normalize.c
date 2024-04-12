/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:46:19 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/10 17:39:13 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

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

t_vector3	vector3_normalize(t_vector3 vec)
{
/* 	double		mag;
	t_vector3	normalized_vec; */

/* 	mag = magnitude(vec);
	if (mag != 0)
	{
		normalized_vec.x = vec.x / mag;
		normalized_vec.y = vec.y / mag;
		normalized_vec.z = vec.z / mag;
	}
	else
	{
		normalized_vec.x = 0;
		normalized_vec.y = 0;
		normalized_vec.y = 0;
	} */
	return (vec);
}

t_vector2_int	vector2_int_normalize(t_vector2_int vec)
{
	t_vector2_int	normalized_vec;

	normalized_vec.x = int_sign(vec.x);
	normalized_vec.y = int_sign(vec.y);
	return (normalized_vec);
}

t_vector3_int	vector3_int_normalize(t_vector3_int vec)
{
	t_vector3_int	normalized_vec;

	normalized_vec.x = int_sign(vec.x);
	normalized_vec.y = int_sign(vec.y);
	normalized_vec.z = int_sign(vec.z);
	return (normalized_vec);
}
