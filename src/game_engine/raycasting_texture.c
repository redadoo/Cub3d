/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:29:00 by evocatur          #+#    #+#             */
/*   Updated: 2024/01/31 14:11:16 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	renderer_texture(t_game *game)
{
/* 	int				hit = 0;
	int				side = 0;
	t_ray			ray = {.ray_dir.x = 0,.ray_dir.y = 0};
	t_vector2		side_dist = {.x = 0, .y = 0};
 	double			delta_dist_x;
  	double			delta_dist_y;
	double			perpWallDist;
	t_vector2_int	step = {.x = 0, .y = 0};
	static int		frame;

	char buffer[(int)game->window.size.y][(int)game->window.size.x];

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
	
		int pitch = 100;

		int draw_start = -lineHeight / 2 + game->window.size.y / 2 + pitch;
		if (draw_start < 0) draw_start = 0;
		int draw_end = lineHeight / 2 + game->window.size.y / 2 + pitch;		
		if (draw_end >= game->window.size.y) draw_end = game->window.size.y - 1;
	
		double wallX;
		if (side == 0)	wallX = game->player.pos.y + perpWallDist * ray.ray_dir.y;
		else			wallX = game->player.pos.x + perpWallDist * ray.ray_dir.x;
		wallX -= floor((wallX));

		int texX = (int)(wallX * (double)64);
		if(side == 0 && ray.ray_dir.x > 0) texX = 64 - texX - 1;
		if(side == 1 && ray.ray_dir.y < 0) texX = 64 - texX - 1;

      	double step = 1.0 * 64 / lineHeight;
		
		double texPos = (draw_start - pitch  / 2 + lineHeight / 2) * step;

		for(int y = draw_start; y < draw_end; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (64 - 1);
			texPos += step;
			char *color = texture[texNum][texHeight * texY + texX];
			//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if(side == 1) color = (color >> 1) & 8355711;
			buffer[y][x] = color;
		}

	}
	frame++;
	if (frame == 60)
	{
		mlx_clear_window(game->mlx, game->window.reference);
		frame = 0;
	} */
}
