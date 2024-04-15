/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:12:28 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/12 16:51:40 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "math.h"
# include <stdio.h>
# include "../libft/libft.h"

//vector2
// # define VECTOR2_FORWARD ((t_vector2){0, 1})
// # define VECTOR2_BACK ((t_vector2){0, -1})
// # define VECTOR2_RIGHT ((t_vector2){1, 0})
// # define VECTOR2_LEFT ((t_vector2){-1, 0})
//vector3
// # define VECTOR3_FORWARD ((t_vector3){0, 1})
// # define VECTOR3_BACK ((t_vector3){0, -1})
// # define VECTOR3_RIGHT ((t_vector3){1, 0})
// # define VECTOR3_LEFT ((t_vector3){-1, 0})

/**
 * @brief Structure representing a 2D integer vector.
 */
typedef struct s_vector2_int
{
	int		x;
	int		y;
}			t_vector2_int;

/**
 * @brief Structure representing a 2D double vector.
 */
typedef struct s_vector2
{
	double	x;
	double	y;
}			t_vector2;

/**
 * @brief Structure representing a 3D integer vector.
 */
typedef struct s_vector3_int
{
	int		x;
	int		y;
	int		z;
}			t_vector3_int;

/**
 * @brief Structure representing a 3D double vector.
 */
typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}			t_vector3;

/**
 * @brief Returns the sign of an integer value.
 *
 * @param val The value to determine the sign of.
 * @return The sign of the value (-1 if negative, 1 if positive, 0 if zero).
 */
int				int_sign(int val);

/**
 * @brief Calculates the magnitude of a 2D vector.
 *
 * @param vec The vector for which to calculate magnitude.
 * @return The magnitude of the vector.
 */
double			magnitude(t_vector2 vec);

/**
 * @brief Converts a string to a 3D double vector.
 *
 * @param str The string containing the vector components (e.g., "255,255,255").
 * @return The resulting 3D double vector.
 */
t_vector3		string_to_vector3(char *str);

/**
 * @brief Converts a string to a 3D integer vector.
 *
 * @param str The string containing the vector components (e.g., "255,255,255").
 * @return The resulting 3D integer vector.
 */
t_vector3_int	string_to_vector3_int(char *str);

/**
 * @brief Converts a string to a 2D double vector.
 *
 * @param str The string containing the vector components (e.g., "255,255").
 * @return The resulting 2D double vector.
 */
t_vector2		string_to_vector2(char *str);

/**
 * @brief Converts a string to a 2D integer vector.
 *
 * @param str The string containing the vector components (e.g., "255,255").
 * @return The resulting 2D integer vector.
 */
t_vector2_int	string_to_vector2_int(char *str);

/**
 * @brief Sets the values of a 2D integer vector.
 *
 * @param v A reference to the t_vector2_int structure.
 * @param x The new X value.
 * @param y The new Y value.
 */
void			set_vector2_int(t_vector2_int *v, int x, int y);

/**
 * @brief Sets the values of a 3D integer vector.
 *
 * @param v A reference to the t_vector3_int structure.
 * @param x The new X value.
 * @param y The new Y value.
 * @param z The new Z value.
 */
void			set_vector3_int(t_vector3_int *v, int x, int y, int z);

/**
 * @brief Sets the values of a 3D double vector.
 *
 * @param v A reference to the t_vector3 structure.
 * @param x The new X value.
 * @param y The new Y value.
 * @param z The new Z value.
 */
void			set_vector3(t_vector3 *v, double x, double y, double z);

/**
 * @brief Sets the values of a 2D double vector.
 *
 * @param v A reference to the t_vector2 structure.
 * @param x The new X value.
 * @param y The new Y value.
 */
void			set_vector2(t_vector2 *v, double x, double y);

/**
 * @brief Calculates the direction vector between two 2D double vectors.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The direction vector from a to b.
 */
t_vector2		vector2_direction(t_vector2 a, t_vector2 b);

/**
 * @brief Calculates the direction vector between two 3D double vectors.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The direction vector from a to b.
 */
t_vector3		vector3_direction(t_vector3 a, t_vector3 b);

/**
 * @brief Calculates the direction vector between two 2D integer vectors.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The direction vector from a to b.
 */
t_vector2_int	vector2_int_direction(t_vector2_int a, t_vector2_int b);

/**
 * @brief Calculates the direction vector between two 3D integer vectors.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return The direction vector from a to b.
 */
t_vector3_int	vector3_int_direction(t_vector3_int a, t_vector3_int b);

/**
 * @brief Normalizes a 2D double vector.
 *
 * @param vec The vector to normalize.
 * @return The normalized vector.
 */
t_vector2		vector2_normalize(t_vector2 vec);

/**
 * @brief Normalizes a 3D double vector.
 *
 * @param vec The vector to normalize.
 * @return The normalized vector.
 */
t_vector3		vector3_normalize(t_vector3 vec);

/**
 * @brief Normalizes a 2D integer vector.
 *
 * @param vec The vector to normalize.
 * @return The normalized vector.
 */
t_vector2_int	vector2_int_normalize(t_vector2_int vec);

/**
 * @brief Normalizes a 3D integer vector.
 *
 * @param vec The vector to normalize.
 * @return The normalized vector.
 */
t_vector3_int	vector3_int_normalize(t_vector3_int vec);

/**
 * @brief Prints a 2D double vector to stdout.
 *
 * @param v The vector to print.
 */
void			print_vector2(t_vector2 v);

/**
 * @brief Prints a 3D double vector to stdout.
 *
 * @param v The vector to print.
 */
void			print_vector3(t_vector3 v);

/**
 * @brief Prints a 2D integer vector to stdout.
 *
 * @param v The vector to print.
 */
void			print_vector2_int(t_vector2_int v);

/**
 * @brief Prints a 3D integer vector to stdout.
 *
 * @param v The vector to print.
 */
void			print_vector3_int(t_vector3_int v);

int				compare_vector2_int(t_vector2_int v1, t_vector2_int v2);
#endif