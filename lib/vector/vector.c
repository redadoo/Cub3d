/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:01:43 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/29 21:54:46 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector2	vector2_lerp(t_vector2 a, t_vector2 b, float t)
{
	t_vector2	res;

	if (t < 0) 
		t = 0;
	else if (t > 1) 
		t = 1;
	res.x = a.x + (b.x - a.x) * t;
	res.y = a.y + (b.y - a.y) * t;
	return (res);
}

t_vector2	vector2_lerp_unclamped(t_vector2 a, t_vector2 b, float t)
{
	t_vector2	res;

	res.x = a.x + (b.x - a.x) * t;
	res.y = a.y + (b.y - a.y) * t;
	return (res);
}

t_vector3	vector3_lerp(t_vector3 a, t_vector3 b, float t)
{
	t_vector3	res;

	if (t < 0)
		t = 0;
	else if (t > 1)
		t = 1;
	res.x = a.x + (b.x - a.x) * t;
	res.y = a.x + (b.y - a.y) * t;
	res.z = a.x + (b.z - a.z) * t;
	return (res);
}

t_vector2	vector3_lerp_unclamped(t_vector3 a, t_vector3 b, float t)
{
	t_vector2	res;

	res.x = a.x + (b.x - a.x) * t;
	res.y = a.y + (b.y - a.y) * t;
	return (res);
}

t_vector2 vector2_dir(t_vector2 a, t_vector2 b)
{
	t_vector2 dir;

	dir.x = a.x - b.x;
	dir.y = a.y - b.y;

	return (dir);
}

t_vector3 vector3_dir(t_vector3 a, t_vector3 b)
{
	t_vector3 dir;

	dir.x = a.x - b.x;
	dir.z = a.z - b.z;
	dir.y = a.y - b.y;
	
	return (dir);
}