/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:21:39 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/03 16:54:33 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static uint32_t	get_color(t_game *game, t_raycaster *rc)
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

void	draw_minimap(t_game *game)
{
	int				i;
	int				y;
	int				offset_draw;
	t_vector2_int	offset_title;

	i = 0;
	y = 0;
	offset_draw = game->mini_map.offset_draw;
	game->mini_map.sprite
		= new_img(game->mlx, matrix_width(game->map) * offset_draw,
			matrix_height(game->map) * offset_draw);
	while (game->map[y])
	{
		while (game->map[y][i])
		{
			set_vector2_int(
				&offset_title, i * offset_draw, y * offset_draw);
			if (game->map[y][i] == '1')
				draw_quad(&game->mini_map.sprite,
					offset_title, 5, create_trgb(256, game->mini_map.title_color));
			i++;
		}
		i = 0;
		y++;
	}
	set_vector2_int(&offset_title,game->player.pos.x * offset_draw,game->player.pos.z * offset_draw);
	draw_quad(&game->mini_map.sprite, offset_title, 4, create_trgb(256, game->mini_map.player_color));
}
