/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:12:28 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/05 14:52:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "math.h"
# include <stdio.h>
# include "../libft/libft.h"

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

t_vector3	string_to_vector(char *str);
void		set_vector2_int(t_vector2_int *v, int x, int y);
void		set_vector3_int(t_vector3_int *v, int x, int y, int z);
void		set_vector3(t_vector3 *v, double x, double y, double z);
void		set_vector2(t_vector2 *v, double x, double y);
t_vector3	vector3_direction(t_vector3 a, t_vector3 b);
t_vector3	vector3_direction_normalize(t_vector3 a, t_vector3 b);
#endif