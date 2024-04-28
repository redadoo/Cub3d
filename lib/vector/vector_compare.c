/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:50:35 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/28 22:55:24 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

bool	compare_vector2_int(t_vector2_int v1, t_vector2_int v2)
{
	if (v1.x == v2.x && v1.y == v2.y)
		return (true);
	return (false);
}

bool	compare_vector2(t_vector2 v1, t_vector2 v2)
{
	if (v1.x == v2.x && v1.y == v2.y)
		return (true);
	return (false);
}

bool	compare_vector3_int(t_vector3_int v1, t_vector3_int v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return (true);
	return (false);
}

bool	compare_vector3(t_vector3 v1, t_vector3 v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return (true);
	return (false);
}
