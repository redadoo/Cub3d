/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:47:49 by codespace         #+#    #+#             */
/*   Updated: 2024/04/05 14:49:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector3	string_to_vector(char *str)
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
