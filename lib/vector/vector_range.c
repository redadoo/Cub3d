/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:05:13 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/29 00:22:03 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

bool    is_vector3_in_range(t_vector3 v, double min_range, double max_range)
{
    return ((v.x >= min_range && v.x <= max_range) && (v.y >= min_range && v.y <= max_range) && (v.z >= min_range && v.z <= max_range));
}

bool    is_vector3_int_in_range(t_vector3_int v, int min_range, int max_range)
{
    return ((v.x >= min_range && v.x <= max_range) && (v.y >= min_range && v.y <= max_range) && (v.z >= min_range && v.z <= max_range));
}

bool    is_vector2_in_range(t_vector2 v, double min_range, double max_range)
{
    return ((v.x >= min_range && v.x <= max_range) && (v.y >= min_range && v.y <= max_range));
}

bool    is_vector2_int_in_range(t_vector2_int v, int min_range, int max_range)
{
    return ((v.x >= min_range && v.x <= max_range) && (v.y >= min_range && v.y <= max_range));
}