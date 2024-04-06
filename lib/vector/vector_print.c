/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:34:16 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/06 17:38:10 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	print_vector2(t_vector2 v)
{
	printf("x : %.2f | y : %.2f \n", v.x, v.y);
}

void	print_vector2_int(t_vector2_int v)
{
	printf("x : %d | y : %d \n", v.x, v.y);
}
