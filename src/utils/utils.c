/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:17:47 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/30 15:27:28 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_dir(char ch)
{
	if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
		return (1);
	return (0);
}

void	print_matrix(char **matrix)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (matrix[i])
	{
		while (matrix[i][j])
		{
			if (matrix[i][j] == '1')
				printf("\033[0;36m%c", matrix[i][j]);
			else if (matrix[i][j] == '2')
				printf("\033[0;32m%c", matrix[i][j]);
			else if (matrix[i][j] == '3')
				printf("\033[0;34m%c", matrix[i][j]);
			else if (matrix[i][j] == '4')
				printf("\033[0;33m%c", matrix[i][j]);
			else if (matrix[i][j] == '5')
				printf("\033[0;31m%c", matrix[i][j]);
			else if (matrix[i][j] == '0')
				printf("\033[0;37m%c", matrix[i][j]);
			else if (check_dir(matrix[i][j]) == 1)
				printf("\033[0;33m%c", matrix[i][j]);
			else if (matrix[i][j] != '\n')
				printf("%c", matrix[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

void	print_vector3(t_vector3 v)
{
	printf("x : %.2f ", v.x);
	printf("z : %.2f ", v.z);
	printf("y : %.2f \n", v.y);
}
void	print_vector2(t_vector2 v)
{
	printf("x : %.2f ", v.x);
	printf("y : %.2f \n", v.y);
}

void	set_vector3(t_vector3 *v, double x, double y, double z)
{
	v->x = x;
	v->z = z;
	v->y = y;
}

void	set_vector2(t_vector2 *v, double x, double y)
{
	v->x = x;
	v->y = y;
}
