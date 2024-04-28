/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:31:15 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/06 15:35:49 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	int_sign(int val)
{
	return ((val > 0) - (val < 0));
}

double	magnitude(t_vector2 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}
