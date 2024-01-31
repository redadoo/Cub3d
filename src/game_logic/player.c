/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:07 by edoardo           #+#    #+#             */
/*   Updated: 2024/01/31 15:59:52 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int check_matrix(t_game *game, int x, int y)
{
	if (game->map.map[y][x])
		return (1);
	return (0);
}

void	init_player(t_player *player, char **map)
{
	t_vector2_int	i;

	i.x = 0;
	i.y = 0;
	while (map[i.y])
	{
		while (map[i.y][i.x])
		{
			if (map[i.y][i.x] == 'N')
			{
				set_vector3(&player->pos, (double)i.x + 1,0.0f,(double)i.y + 1);
				set_vector2(&player->dir, 0, 1);
				set_vector2_int(&player->map_pos, i.x + 1, i.y + 1);
				return ;
			}
			if (map[i.y][i.x] == 'S')
			{
				set_vector3(&player->pos, (double)i.x + 1,0.0f,(double)i.y + 1);
				set_vector2(&player->dir,0, -1);
				set_vector2_int(&player->map_pos, i.x + 1, i.y + 1);
				return ;
			}
			if (map[i.y][i.x] == 'E')
			{
				set_vector3(&player->pos, (double)i.x + 1,0.0f,(double)i.y + 1);
				set_vector2(&player->dir,1, 0);
				set_vector2_int(&player->map_pos, i.x + 1, i.y + 1);
				return ;
			}
			if (map[i.y][i.x] == 'W')
			{
				set_vector3(&player->pos, (double)i.x + 1,0.0f,(double)i.y + 1);
				set_vector2(&player->dir,-1, 0);
				set_vector2_int(&player->map_pos, i.x + 1, i.y + 1);
				return ;
			}
			i.x++;
		}
		i.x = 0;
		i.y++;
	}
}

void move_player(t_game *game, int dir)
{
	game->player.movement_speed = 0.2F;
	game->player.rotation_speed = 0.2F;
	double movement_speed = game->player.movement_speed;
	double rotation_speed = game->player.rotation_speed;

	if(dir == DOWN)
	{
		printf("su\n");
		if (game->map.map[(int)(game->player.pos.z + game->player.dir.y * movement_speed)][(int)game->player.pos.x] == '0')
		{
			game->player.pos.x += game->player.dir.x * movement_speed;
		}
		if (game->map.map[(int)(game->player.pos.z)][(int)(game->player.pos.x + game->player.dir.x * movement_speed)] == '0')
		{
			game->player.pos.z += game->player.dir.y * movement_speed;
		}
	}
	if(dir == UP)
	{
		printf("dietro\n");
		if (game->map.map[(int)(game->player.pos.z - game->player.dir.y * movement_speed)][(int)game->player.pos.z] == '0')
		{
			game->player.pos.x -= game->player.dir.x * game->player.movement_speed;
		}
		if (game->map.map[(int)(game->player.pos.z)][(int)(game->player.pos.x - game->player.dir.x * movement_speed)] == '0')
		{
			game->player.pos.z -= game->player.dir.y * movement_speed;
		}
	}
	if(dir == RIGHT)
	{
		printf("destra\n");
		double oldDirX = game->player.dir.x;
      	game->player.dir.x = game->player.dir.x * cos(-rotation_speed) - game->player.dir.y * sin(-rotation_speed);
		game->player.dir.y = oldDirX * sin(-rotation_speed) + game->player.dir.y * cos(-rotation_speed);
	    double oldPlaneX = game->camera.camera_plane.x;
		game->camera.camera_plane.x = game->camera.camera_plane.x * cos(-rotation_speed) - game->camera.camera_plane.y * sin(-rotation_speed);
      	game->camera.camera_plane.y = oldPlaneX * sin(-rotation_speed) + game->camera.camera_plane.y * cos(-rotation_speed);
	}
	if(dir == LEFT)
	{
		printf("sinistra\n");
		double oldDirX = game->player.dir.x;
		game->player.dir.x = game->player.dir.x * cos(rotation_speed) - game->player.dir.y * sin(rotation_speed);
		game->player.dir.y = oldDirX * sin(game->player.rotation_speed) + game->player.dir.y * cos(rotation_speed);
		double oldPlaneX = game->camera.camera_plane.x;
		game->camera.camera_plane.x = game->camera.camera_plane.x * cos(rotation_speed) - game->camera.camera_plane.y * sin(rotation_speed);
		game->camera.camera_plane.y = oldPlaneX * sin(rotation_speed) + game->camera.camera_plane.y * cos(rotation_speed);
	}
}
