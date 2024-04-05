/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:26:34 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/05 16:42:28 by evocatur         ###   ########.fr       */
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
