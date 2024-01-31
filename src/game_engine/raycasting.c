/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:29:00 by evocatur          #+#    #+#             */
/*   Updated: 2024/01/31 16:28:22 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int64_t currentTimeMillis() {
  struct timeval time;
  gettimeofday(&time, NULL);
  int64_t s1 = (int64_t)(time.tv_sec) * 1000;
  int64_t s2 = (time.tv_usec / 1000);
  return s1 + s2;
}

void	renderer(t_game *game)
{
	int				hit;
	int				side;
	t_ray			ray;
	t_vector2		side_dist;
	t_vector2		delta_dist;
	double			perpWallDist;
	t_vector2_int	step;
	int				time;
	int				old_time;


	for (int x = 0; x < game->window.size.x; x++)
	{
		game->camera.pos.x = 2 * x / game->window.size.x - 1;
		ray.ray_dir.x = game->player.dir.x + game->camera.camera_plane.x * game->camera.pos.x;
		ray.ray_dir.y = game->player.dir.y + game->camera.camera_plane.y * game->camera.pos.x;
		game->player.map_pos.x = (int)game->player.pos.x;
		game->player.map_pos.y = (int)game->player.pos.z;
		delta_dist.x = (ray.ray_dir.x == 0) ? 1e30 : fabs(1 / ray.ray_dir.x);
		delta_dist.y = (ray.ray_dir.y == 0) ? 1e30 : fabs(1 / ray.ray_dir.y);
		hit = 0;
		if (ray.ray_dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (game->player.pos.x * game->player.map_pos.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (game->player.map_pos.x + 1.0 - game->player.pos.x) * delta_dist.x;
		}
		if (ray.ray_dir.y < 0)
		{
			step.y = -1;
			side_dist.y = (game->player.pos.y * game->player.map_pos.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (game->player.map_pos.y + 1.0 - game->player.pos.y) * delta_dist.y;
		}
		
		while (hit == 0)
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				game->player.map_pos.x += step.x;
				side = 0;
			}
			else
			{
				side_dist.y += delta_dist.y;
				game->player.map_pos.y += step.y;
				side = 1;
			}
			if(game->map.map[game->player.map_pos.x][game->player.map_pos.y] > 0)
				hit = 1;
		}
		if(side == 0)	perpWallDist = (side_dist.x - delta_dist.x);
		else			perpWallDist = (side_dist.y - delta_dist.y);
		
		int lineHeight = (int)(game->window.size.y / perpWallDist);
		int drawStart = -lineHeight / 2 + (int)game->window.size.y / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + (int)game->window.size.y / 2;
		if(drawEnd >= (int)game->window.size.y) drawEnd = (int)game->window.size.y - 1;

		t_vector3 color;

		if (game->map.map[game->player.map_pos.y][game->player.map_pos.x] == '1') set_vector3(&color ,255, 0, 0);
		else if (game->map.map[game->player.map_pos.y][game->player.map_pos.x] == '2') set_vector3(&color ,0, 128, 0);
		else if (game->map.map[game->player.map_pos.y][game->player.map_pos.x] == '3') set_vector3(&color ,0, 0, 255);
		else if (game->map.map[game->player.map_pos.y][game->player.map_pos.x] == '4') set_vector3(&color ,255, 255, 0);
		else if (game->map.map[game->player.map_pos.y][game->player.map_pos.x] == '5') set_vector3(&color ,255, 255, 255);
		else set_vector3(&color ,255, 255, 255);
		
		if(side == 1) divide_vector3(&color,2);

		draw_vert_line(x, drawStart, drawEnd, color, game);
	}
	
	old_time = time;
	time = currentTimeMillis();
    double frameTime = (time - old_time) / 1000.0;
	mlx_clear_window(game->mlx, game->window.reference);
}
