/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:29:00 by evocatur          #+#    #+#             */
/*   Updated: 2024/01/31 14:13:26 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	renderer(t_game *game)
{
	int				hit = 0;
	int				side = 0;
	t_ray			ray = {.ray_dir.x = 0,.ray_dir.y = 0};
	t_vector2		side_dist = {.x = 0, .y = 0};
 	double			delta_dist_x;
  	double			delta_dist_y;
	double			perpWallDist;
	t_vector2_int	step = {.x = 0, .y = 0};
	static int		frame;

	for (int x = 0; x < game->window.size.x; x++)
	{
		game->camera.pos.x = 2 * x / game->window.size.x - 1;
		
		ray.ray_dir.x = game->player.dir.x + game->camera.camera_plane.x * game->camera.pos.x;
		ray.ray_dir.y = game->player.dir.y + game->camera.camera_plane.y * game->camera.pos.x;

		game->player.map_pos.x = (int)game->player.pos.x;
		game->player.map_pos.y = (int)game->player.pos.z;

		delta_dist_x = (ray.ray_dir.x == 0) ? 1e30 : fabs(1 / ray.ray_dir.x);
		delta_dist_y = (ray.ray_dir.y == 0) ? 1e30 : fabs(1 / ray.ray_dir.y);

		if (ray.ray_dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (game->player.pos.x - game->player.map_pos.x) * delta_dist_x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (game->player.map_pos.x + 1.0 - game->player.pos.x) * delta_dist_x;
		}
		if (ray.ray_dir.y < 0)
		{
			step.y = -1;
			side_dist.y = (game->player.pos.z - game->player.map_pos.y) * delta_dist_y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (game->player.map_pos.y + 1.0 - game->player.pos.z) * delta_dist_y;
		}
		
		while(hit == 0)
		{
			if (side_dist.x > side_dist.y)
			{
				side_dist.x += delta_dist_x;
				game->player.map_pos.x += step.x;
				side = 0;
			}
			else
			{
				side_dist.y += delta_dist_y;
				game->player.map_pos.y += step.y;
				side = 1;
			}
        	if (game->map.map[game->player.map_pos.y][game->player.map_pos.x] != '0') hit = 1;
		}
		
		if (side == 0)	perpWallDist = (side_dist.x - delta_dist_x);
		else 			perpWallDist = (side_dist.y - delta_dist_y);

		int lineHeight = (int)(game->window.size.y / perpWallDist);

		int drawStart = (-lineHeight / 2) + (game->window.size.y / 2);

		if(drawStart < 0)
			drawStart = 1;
		
		int drawEnd = lineHeight / 2 + game->window.size.y / 2;
		if(drawEnd >= game->window.size.y) drawEnd = game->window.size.y - 1;

		t_vector3 color;

		if (game->map.map[game->player.map_pos.y][game->player.map_pos.x] == '1') set_vector3(&color ,255, 0, 0);
		if (game->map.map[game->player.map_pos.y][game->player.map_pos.x] == '2') set_vector3(&color ,0, 128, 0);
		if (game->map.map[game->player.map_pos.y][game->player.map_pos.x] == '3') set_vector3(&color ,0, 0, 255);
		if (game->map.map[game->player.map_pos.y][game->player.map_pos.x] == '4') set_vector3(&color ,255, 255, 0);
		if (game->map.map[game->player.map_pos.y][game->player.map_pos.x] == '5') set_vector3(&color ,255, 255, 255);

		draw_vert_line(x, drawStart, drawEnd, color, game);
	}
	frame++;
	if (frame == 60)
	{
		mlx_clear_window(game->mlx, game->window.reference);
	}
    if (frame == 120)
    {
		frame = 0;
    }
}
