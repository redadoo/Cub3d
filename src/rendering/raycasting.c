/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:29:00 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/10 15:36:03 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	set_raycaster(t_game *game, int x)
{
	game->raycaster.camera_x = 2 * x / (double)WIN_WIDTH - 1;
	set_vector2(&game->raycaster.ray_dir, game->camera.dir.x
		+ game->camera.plane.x * game->raycaster.camera_x, game->camera.dir.y
		+ game->camera.plane.y * game->raycaster.camera_x);
	set_vector2_int(&game->raycaster.vec_map, (int)game->player.pos.x,
		(int)game->player.pos.z);
	set_vector2(&game->raycaster.delta_dist, fabs(1
			/ game->raycaster.ray_dir.x), fabs(1 / game->raycaster.ray_dir.y));
	game->raycaster.hit = 0;
}

void	set_raycaster_dir(t_game *game)
{
	if (game->raycaster.ray_dir.x < 0)
	{
		game->raycaster.vec_step.x = -1;
		game->raycaster.side_dist.x = (game->player.pos.x
				- game->raycaster.vec_map.x) * game->raycaster.delta_dist.x;
	}
	else
	{
		game->raycaster.vec_step.x = 1;
		game->raycaster.side_dist.x = (game->raycaster.vec_map.x + 1.0f
				- game->player.pos.x) * game->raycaster.delta_dist.x;
	}
	if (game->raycaster.ray_dir.y < 0)
	{
		game->raycaster.vec_step.y = -1;
		game->raycaster.side_dist.y = (game->player.pos.z
				- game->raycaster.vec_map.y) * game->raycaster.delta_dist.y;
	}
	else
	{
		game->raycaster.vec_step.y = 1;
		game->raycaster.side_dist.y = (game->raycaster.vec_map.y + 1.0f
				- game->player.pos.z) * game->raycaster.delta_dist.y;
	}
}

void	find_distance_tw_wall(t_game *game)
{
	while (!game->raycaster.hit)
	{
		if (game->raycaster.side_dist.x < game->raycaster.side_dist.y)
		{
			game->raycaster.side_dist.x += game->raycaster.delta_dist.x;
			game->raycaster.vec_map.x += game->raycaster.vec_step.x;
			game->raycaster.side = 0;
		}
		else
		{
			game->raycaster.side_dist.y += game->raycaster.delta_dist.y;
			game->raycaster.vec_map.y += game->raycaster.vec_step.y;
			game->raycaster.side = 1;
		}
		if (game->map[game->raycaster.vec_map.y]
			[game->raycaster.vec_map.x] == '1')
			game->raycaster.hit = 1;
	}
}

void	find_wall_height(t_game *game)
{
	if (!game->raycaster.side)
		game->raycaster.perp_wall_dist = game->raycaster.side_dist.x
			- game->raycaster.delta_dist.x;
	else
		game->raycaster.perp_wall_dist = game->raycaster.side_dist.y
			- game->raycaster.delta_dist.y;
	game->raycaster.line_height = (int)(WIN_HEIGHT
			/ game->raycaster.perp_wall_dist);
	game->raycaster.draw_start = -game->raycaster.line_height / 2 + WIN_HEIGHT
		/ 2 + 100;
	if (game->raycaster.draw_start < 0)
		game->raycaster.draw_start = 0;
	game->raycaster.draw_end = game->raycaster.line_height / 2 + WIN_HEIGHT / 2
		+ 100;
	if (game->raycaster.draw_end >= WIN_HEIGHT)
		game->raycaster.draw_end = WIN_HEIGHT - 1;
}

void	find_wall_pixel(t_game *game)
{
	if (!game->raycaster.side)
		game->raycaster.wall_x = (int)game->player.pos.z
			+ game->raycaster.perp_wall_dist * game->raycaster.ray_dir.y;
	else
		game->raycaster.wall_x = (int)game->player.pos.x
			+ game->raycaster.perp_wall_dist * game->raycaster.ray_dir.x;
	game->raycaster.wall_x -= floor(game->raycaster.wall_x);
	game->raycaster.tex.x = (int)(game->raycaster.wall_x
			* (double)TEXTURE_WIDTH);
	if (!game->raycaster.side && game->raycaster.ray_dir.x > 0)
		game->raycaster.tex.x = TEXTURE_WIDTH - game->raycaster.tex.x - 1;
	if (game->raycaster.side && game->raycaster.ray_dir.y < 0)
		game->raycaster.tex.x = TEXTURE_WIDTH - game->raycaster.tex.x - 1;
	game->raycaster.step = 1.0 * TEXTURE_HEIGHT / game->raycaster.line_height;
	game->raycaster.tex_pos = (game->raycaster.draw_start - 100 - WIN_HEIGHT / 2
			+ game->raycaster.line_height / 2) * game->raycaster.step;
}
