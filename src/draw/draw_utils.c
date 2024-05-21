/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:22:16 by fborroto          #+#    #+#             */
/*   Updated: 2024/05/21 17:46:52 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	draw_quad(t_sprite sprite, t_vector2_int offset, int lenght, int color)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < lenght)
	{
		while (y < lenght)
		{
			ft_put_pixel(sprite, offset.x + i, offset.y + y, color);
			y++;
		}
		y = 0;
		i++;
	}
}

int	create_trgb(int t, t_vector3_int rgb)
{
	return (t << 24 | rgb.x << 16 | rgb.y << 8 | rgb.z);
}
