/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:22:16 by fborroto          #+#    #+#             */
/*   Updated: 2024/04/03 19:24:58 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	draw_quad(t_sprite *sprite, t_vector2_int offset, int lenght, int color)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < lenght)
	{
		while (y < lenght)
		{
			put_pixel(sprite, offset.x + i, offset.y + y, color);
			y++;
		}
		y = 0;
		i++;
	}
}
