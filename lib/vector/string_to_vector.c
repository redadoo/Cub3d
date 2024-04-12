/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:47:49 by codespace         #+#    #+#             */
/*   Updated: 2024/04/10 15:32:13 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector3	string_to_vector3(char *str)
{
	t_vector3	v;
	char		**numbers;

	numbers = ft_split(str, ',');
	v.x = ft_atoi(numbers[0]);
	v.y = ft_atoi(numbers[1]);
	v.z = ft_atoi(numbers[2]);
	free_matrix(numbers);
	return (v);
}

t_vector3_int	string_to_vector3_int(char *str)
{
	t_vector3_int	v;
	char			**numbers;

	numbers = ft_split(str, ',');
	v.x = ft_atoi(numbers[0]);
	v.y = ft_atoi(numbers[1]);
	v.z = ft_atoi(numbers[2]);
	free_matrix(numbers);
	return (v);
}

t_vector2	string_to_vector2(char *str)
{
	t_vector2	v;
	char		**numbers;

	numbers = ft_split(str, ',');
	v.x = ft_atoi(numbers[0]);
	v.y = ft_atoi(numbers[1]);
	free_matrix(numbers);
	return (v);
}

t_vector2_int	string_to_vector2_int(char *str)
{
	t_vector2_int	v;
	char			**numbers;

	numbers = ft_split(str, ',');
	v.x = ft_atoi(numbers[0]);
	v.y = ft_atoi(numbers[1]);
	free_matrix(numbers);
	return (v);
}
