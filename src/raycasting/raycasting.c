/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:29:00 by evocatur          #+#    #+#             */
/*   Updated: 2024/05/21 17:43:48 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	set_raycaster(t_game *game, int x)
{
	t_vector2	delta;

	game->raycaster.camera_x = 2 * x / (double)WIN_WIDTH - 1;
	set_vector2(&game->raycaster.ray_dir, game->camera.dir.x
		+ game->camera.plane.x * game->raycaster.camera_x, game->camera.dir.y
		+ game->camera.plane.y * game->raycaster.camera_x);
	set_vector2_int(&game->raycaster.vec_map, game->player.pos.x,
		game->player.pos.z);
	if (game->raycaster.ray_dir.x == 0)
		delta.x = 1e30;
	else
		delta.x = fabs(1 / game->raycaster.ray_dir.x);
	if (game->raycaster.ray_dir.y == 0)
		delta.y = 1e30;
	else
		delta.y = fabs(1 / game->raycaster.ray_dir.y);
	game->raycaster.delta_dist = delta;
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

void	start_dda(t_game *game)
{
	while (game->raycaster.hit == 0)
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

void	ray_distance(t_game *game)
{
	if (game->raycaster.side == 0)
		game->raycaster.perp_wall_dist = game->raycaster.side_dist.x
			- game->raycaster.delta_dist.x;
	else
		game->raycaster.perp_wall_dist = game->raycaster.side_dist.y
			- game->raycaster.delta_dist.y;
}

void	pixel_to_fill(t_game *game)
{
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
