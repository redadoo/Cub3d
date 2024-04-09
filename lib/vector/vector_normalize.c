/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:46:19 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/09 11:46:41 by edoardo          ###   ########.fr       */
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


t_vector2_int	vector2_int_normalize(t_vector2_int vec)
{
	t_vector2_int	normalized_vec;

	normalized_vec.x = int_sign(vec.x);
	normalized_vec.y = int_sign(vec.y);
	return (normalized_vec);
}