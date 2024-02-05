/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:21:39 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/03 18:35:43 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

bool	draw_vert_line(t_game *game, int x)
{
	int	y;

	y = -1;
	while (++y < game->raycaster.draw_start)
	{
		put_pixel_in_canvas(&game->img, x, y, create_trgb(10, 0, 0, 255));
	}
	y = game->raycaster.draw_start;
	while (y < game->raycaster.draw_end)
	{
		game->raycaster.tex.y = (int)game->raycaster.tex_pos & (TEXTURE_HEIGHT
				- 1);
		game->raycaster.tex_pos += game->raycaster.step;
		y += 1;
	}
	y = game->raycaster.draw_end;
	while (y < WIN_HEIGHT)
	{
		put_pixel_in_canvas(&game->img, x, y, create_trgb(10, 255, 0, 0));
		y += 1;
	}
	return (1);
}
