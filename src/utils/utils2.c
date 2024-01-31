/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:34:36 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/29 12:35:55 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_vector3   divide_vector3(t_vector3 v, int div)
{
    t_vector3   r;

    r.x = v.x / div;
    r.y = v.y / div;
    r.z = v.z / div;
    return (r);
}