/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:21:18 by edoardo           #+#    #+#             */
/*   Updated: 2023/11/26 13:09:37 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_extension(char *file)
{
	int		count;
	char	*tmp;

	count = 4;
	tmp = (char *)ft_strstr(file, ".cub");
	if (tmp == NULL)
		return (1);
	while (count)
	{
		tmp++;
		count--;
	}
	if ((int)*tmp != 0)
		return (1);
	count = open(file, O_RDONLY);
	if (count == -1)
		return (1);
	close(count);
	return (0);
}

t_vector3	string_to_vector(char *str)
{
	int			i;
	t_vector3	v;
	char		**numbers;

	i = 0;
	numbers = ft_split(str, ',');
	v.x = ft_atoi(numbers[0]);
	v.y = ft_atoi(numbers[1]);
	v.z = ft_atoi(numbers[2]);
	free_matrix(numbers);
	return (v);
}
