/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:37:29 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/06 14:33:32 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	set_vector2_int(t_vector2_int *v, int x, int y)
{
	v->x = x;
	v->y = y;
}

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
