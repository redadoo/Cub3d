/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:34:36 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/03 18:03:01 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	divide_vector3(t_vector3 *v, int div)
{
	if (v->x != 0)
		v->x /= div;
	if (v->y != 0)
		v->y /= div;
	if (v->z != 0)
		v->z /= div;
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

void	set_vector2_int(t_vector2_int *v, int x, int y)
{
	v->x = x;
	v->y = y;
}
