/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:12:28 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/09 16:39:55 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "math.h"
# include <stdio.h>
# include "../libft/libft.h"

//vector2
// # define FORWARD ((t_vector2){0, 1})
// # define BACK ((t_vector2){0, -1})
// # define RIGHT ((t_vector2){1, 0})
// # define LEFT ((t_vector2){-1, 0})

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

//Math
int				int_sign(int val);
double			magnitude(t_vector2 vec);
//Vector Utils
t_vector3		string_to_vector(char *str);
void			set_vector2_int(t_vector2_int *v, int x, int y);
void			set_vector3_int(t_vector3_int *v, int x, int y, int z);
void			set_vector3(t_vector3 *v, double x, double y, double z);
void			set_vector2(t_vector2 *v, double x, double y);
t_vector2		vector2_direction(t_vector2 a, t_vector2 b);
t_vector2		vector2_normalize(t_vector2 vec);
void			print_vector2(t_vector2 v);
t_vector2_int	vector2_int_direction(t_vector2_int a, t_vector2_int b);
void			print_vector2_int(t_vector2_int v);
t_vector3_int	vector3_int_direction(t_vector3_int a, t_vector3_int b);
t_vector3		vector3_direction(t_vector3 a, t_vector3 b);
#endif