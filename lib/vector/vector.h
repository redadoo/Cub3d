/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:12:28 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/28 15:27:04 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "math.h"
# include <stdio.h>
# include "../libft/libft.h"

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
 * @param sep string number separator
 * @return The resulting 3D double vector.
 */
bool			string_to_vector3(t_vector3 *v, char *str, char sep);

/**
 * @brief Converts a string to a 3D integer vector.
 *
 * @param str The string containing the vector components (e.g., "255,255,255").
 * @param sep string number separator
 * @return The resulting 3D integer vector.
 */
bool			string_to_vector3_int(t_vector3_int *v, char *str, char sep);

/**
 * @brief Converts a string to a 2D double vector.
 *
 * @param str The string containing the vector components (e.g., "255,255").
 * @param sep string number separator
 * @return The resulting 2D double vector.
 */
bool			string_to_vector2(t_vector2 *v, char *str, char sep);

/**
 * @brief Converts a string to a 2D integer vector.
 *
 * @param str The string containing the vector components (e.g., "255,255").
 * @param sep string number separator
 * @return The resulting 2D integer vector.
 */
bool			string_to_vector2_int(t_vector2_int *v, char *str, char sep);

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

/**
 * @brief compare each elements of two t_vector2_int
 * 
 * @param v1 The first vector.
 * @param v2 The second vector.
 * 
 * @return true if vectors are the same otherwise false
*/
bool			compare_vector2_int(t_vector2_int v1, t_vector2_int v2);

/**
 * @brief compare each elements of two t_vector2
 * 
 * @param v1 The first vector.
 * @param v2 The second vector.
 * 
 * @return true if vectors are the same otherwise false
*/
bool			compare_vector2(t_vector2 v1, t_vector2 v2);

/**
 * @brief compare each elements of two t_vector3_int
 * 
 * @param v1 The first vector.
 * @param v2 The second vector.
 * 
 * @return true if vectors are the same otherwise false
*/
bool			compare_vector3_int(t_vector3_int v1, t_vector3_int v2);

/**
 * @brief compare each elements of two t_vector3
 * 
 * @param v1 The first vector.
 * @param v2 The second vector.
 * 
 * @return true if vectors are the same otherwise false
*/
bool			compare_vector3(t_vector3 v1, t_vector3 v2);

/**
 * @brief checks whether each element of a t_vector3
 * is in a range of minimum(inclusive) and maximum(inclusive)
 * 
 * @param v vector to check.
 * @param min smallest value in the range
 * @param max largest value in the range
 * 
 * @return true if each element of a vector is in range
*/
bool			is_vector3_in_range(t_vector3 v, double min, double max);

/**
 * @brief checks whether each element of a t_vector3_int
 * is in a range of minimum(inclusive) and maximum(inclusive)
 * 
 * @param v vector to check.
 * @param min smallest value in the range
 * @param max largest value in the range
 * 
 * @return true if each element of a vector is in range
*/
bool			is_vector3_int_in_range(t_vector3_int v, int min, int max);

/**
 * @brief checks whether each element of a t_vector2
 * is in a range of minimum(inclusive) and maximum(inclusive)
 * 
 * @param v vector to check.
 * @param min smallest value in the range
 * @param max largest value in the range
 * 
 * @return true if each element of a vector is in range
*/
bool			is_vector2_in_range(t_vector2 v, double min, double max);

/**
 * @brief checks whether each element of a t_vector2_int
 * is in a range of minimum(inclusive) and maximum(inclusive)
 * 
 * @param v vector to check.
 * @param min smallest value in the range
 * @param max largest value in the range
 * 
 * @return true if each element of a vector is in range
*/
bool			is_vector2_int_in_range(t_vector2_int v, int min, int max);
#endif