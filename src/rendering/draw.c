/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:21:39 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 17:16:59 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static inline uint32_t	get_color(t_game *game, t_raycaster *rc)
{
	if (!rc->side)
	{
		if (game->player.pos.x > rc->vec_map.x)
			return (extract_pixel_from_image(&game->assets.w_wall, rc->tex.x,
					rc->tex.y));
		return (extract_pixel_from_image(&game->assets.e_wall, rc->tex.x,
				rc->tex.y));
	}
	if (game->player.pos.z > rc->vec_map.y)
		return (extract_pixel_from_image(&game->assets.n_wall, rc->tex.x,
				rc->tex.y));
	return (extract_pixel_from_image(&game->assets.s_wall, rc->tex.x,
			rc->tex.y));
}

int	create_trgb(int t, t_vector3_int rgb)
{
	return (t << 24 | rgb.x << 16 | rgb.y << 8 | rgb.z);
}

void	draw_vert_line_texture(t_game *game, int x)
{
	int	y;

	y = -1;
	while (++y < game->raycaster.draw_start)
	{
		game->scene.side = 0;
		put_pixel(&game->scene, x, y, create_trgb(256,
				game->assets.celin_color));
	}
	y = game->raycaster.draw_start - 1;
	while (++y < game->raycaster.draw_end)
	{
		game->scene.side = game->raycaster.side;
		game->raycaster.tex.y = (int)game->raycaster.tex_pos & (TEXTURE_HEIGHT
				- 1);
		game->raycaster.tex_pos += game->raycaster.step;
		put_pixel(&game->scene, x, y, get_color(game, &game->raycaster));
	}
	y = game->raycaster.draw_end - 1;
	while (++y < WIN_HEIGHT)
	{
		game->scene.side = 0;
		put_pixel(&game->scene, x, y, create_trgb(256,
				game->assets.floor_color));
	}
}


