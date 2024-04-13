/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:49:27 by codespace         #+#    #+#             */
/*   Updated: 2024/04/13 12:30:46 by edoardo          ###   ########.fr       */
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

t_vector2_int	vector2_int_direction(t_vector2_int a, t_vector2_int b)
{
	t_vector2_int	dir;

	dir.x = a.x - b.x;
	dir.y = a.y - b.y;
	return (dir);
}

t_vector3_int	vector3_int_direction(t_vector3_int a, t_vector3_int b)
{
	t_vector3_int	dir;

	dir.x = a.x - b.x;
	dir.y = a.y - b.y;
	dir.z = a.z - b.z;
	return (dir);
}

t_vector3	vector3_direction(t_vector3 a, t_vector3 b)
{
	t_vector3	dir;

	dir.x = a.x - b.x;
	dir.y = a.y - b.y;
	dir.z = a.z - b.z;
	return (dir);
}
