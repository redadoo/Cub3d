/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:47:49 by codespace         #+#    #+#             */
/*   Updated: 2024/04/28 22:12:41 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

bool	string_to_vector3(t_vector3 *v, char *str, char sep)
{
	size_t	i;
	char	**numbers;

	i = 0;
	numbers = ft_split(str, sep);
	while (numbers[i])
	{
		if (!is_all_digits(numbers[i]))
			return (free_matrix(numbers), false);
		i++;
	} 
	v->x = ft_atoi(numbers[0]);
	v->y = ft_atoi(numbers[1]);
	v->z = ft_atoi(numbers[2]);
	return (free_matrix(numbers), true);
}

bool	string_to_vector3_int(t_vector3_int *v, char *str, char sep)
{
	size_t	i;
	char	**numbers;

	i = 0;
	numbers = ft_split(str, sep);
	while (numbers[i])
	{
		if (!is_all_digits(numbers[i]))
			return (free_matrix(numbers), false);
		i++;
	} 
	v->x = ft_atoi(numbers[0]);
	v->y = ft_atoi(numbers[1]);
	v->z = ft_atoi(numbers[2]);
	return (free_matrix(numbers), true);
}

bool	string_to_vector2(t_vector2 *v,char *str, char sep)
{
	size_t	i;
	char	**numbers;

	i = 0;
	numbers = ft_split(str, sep);
	while (numbers[i])
	{
		if (!is_all_digits(numbers[i]))
			return (free_matrix(numbers), false);
		i++;
	} 
	v->x = ft_atoi(numbers[0]);
	v->y = ft_atoi(numbers[1]);
	return (free_matrix(numbers), true);
}

bool	string_to_vector2_int(t_vector2_int *v, char *str, char sep)
{
	size_t	i;
	char	**numbers;

	i = 0;
	numbers = ft_split(str, sep);
	while (numbers[i])
	{
		if (!is_all_digits(numbers[i]))
			return (free_matrix(numbers), false);
		i++;
	} 
	v->x = ft_atoi(numbers[0]);
	v->y = ft_atoi(numbers[1]);
	return (free_matrix(numbers), true);
}
