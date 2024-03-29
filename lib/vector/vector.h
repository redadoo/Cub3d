/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:12:28 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 11:57:48 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "math.h"
# include <stdio.h>

typedef struct s_vector2_int
{
	int		x;
	int		y;
}			t_vector2_int;

typedef struct s_vector2
{
	double	x;
	double	y;
}			t_vector2;

typedef struct s_vector3_int
{
	int		x;
	int		y;
	int		z;
}			t_vector3_int;

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}			t_vector3;

#endif