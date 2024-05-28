/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:21:39 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/28 15:08:20 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	draw_pixel(t_sprite img, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		*(int *)&img.addr[((x * img.bpp) >> 3) + (y * img.line_len)] = color;
	}
}

static void	draw_texture_color(t_game *game, int x, int start, int index)
{
	int	texcolor;

	if (game->raycaster.side == 0)
	{
		if (game->raycaster.ray_dir.x < 0)
			texcolor = game->assets.n_wall.text_value[index];
		else
			texcolor = game->assets.s_wall.text_value[index];
	}
	else
	{
		if (game->raycaster.ray_dir.y < 0)
			texcolor = game->assets.w_wall.text_value[index];
		else
			texcolor = game->assets.e_wall.text_value[index];
		texcolor = (texcolor >> 1) & 8355711;
	}
	draw_pixel(game->world, x, start, texcolor);
}

void	draw_screen(t_game *game, int x)
{
	int	y;
	int	pitch;

	pitch = 100;
	y = game->raycaster.draw_start;
	game->raycaster.step = 1.0 * TEXTURE_HEIGHT / game->raycaster.line_height;
	game->raycaster.tex_pos = (y - pitch - WIN_HEIGHT / 2
			+ game->raycaster.line_height / 2) * game->raycaster.step;
	render_background(game, x);
	while (y < game->raycaster.draw_end)
	{
		game->raycaster.tex.y = (int)game->raycaster.tex_pos & (TEXTURE_HEIGHT
				- 1);
		game->raycaster.tex_pos += game->raycaster.step;
		draw_texture_color(game, x, y,
			TEXTURE_HEIGHT * game->raycaster.tex.y + game->raycaster.tex.x);
		y++;
	}
}

static void	draw_minimap_utlis(t_game *game, int offset_draw, t_vector2_int of)
{
	set_vector2_int(&of, game->player.pos.x * offset_draw, game->player.pos.z
		* offset_draw);
	draw_quad(game->mini_map.sprite, of, 4, create_trgb(256,
			game->mini_map.player_color));
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
	game->mini_map.sprite = init_img(game->mlx, matrix_width(game->map)
			* offset_draw, matrix_height(game->map) * offset_draw);
	while (game->map[y])
	{
		while (game->map[y][i])
		{
			set_vector2_int(&offset_title, i * offset_draw, y * offset_draw);
			if (game->map[y][i] && game->map[y][i] == '1')
				draw_quad(game->mini_map.sprite, offset_title, 5,
					create_trgb(256, game->mini_map.title_color));
			i++;
		}
		i = 0;
		y++;
	}
	draw_minimap_utlis(game, offset_draw, offset_title);
}
