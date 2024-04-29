/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:28:10 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/29 02:57:28 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	go_ahead(t_game *game)
{
	if (check_next_pos(game, game->player.pos.x + game->camera.dir.x
			* game->player.mov_speed, game->player.pos.z) == 1)
		game->player.pos.x += (game->camera.dir.x * game->player.mov_speed);
	if (check_next_pos(game, game->player.pos.x, game->player.pos.z
			+ game->camera.dir.y * game->player.mov_speed) == 1)
		game->player.pos.z += (game->camera.dir.y * game->player.mov_speed);
}

void	go_backwards(t_game *game)
{
	if (check_next_pos(game, game->player.pos.x - game->camera.dir.x
			* game->player.mov_speed, game->player.pos.z) == 1)
		game->player.pos.x -= (game->camera.dir.x * game->player.mov_speed);
	if (check_next_pos(game, game->player.pos.x, game->player.pos.z
			- game->camera.dir.y * game->player.mov_speed) == 1)
		game->player.pos.z -= (game->camera.dir.y * game->player.mov_speed);
}

void	go_left(t_game *game)
{
	if (check_next_pos(game, game->player.pos.x - game->camera.dir.y
			* game->player.mov_speed, game->player.pos.z) == 1)
		game->player.pos.x -= (game->camera.dir.y * game->player.mov_speed);
	if (check_next_pos(game, game->player.pos.x, game->player.pos.z
			+ game->camera.dir.x * game->player.mov_speed) == 1)
		game->player.pos.z += (game->camera.dir.x * game->player.mov_speed);
}

void	go_right(t_game *game)
{
	if (check_next_pos(game, game->player.pos.x + game->camera.dir.y
			* game->player.mov_speed, game->player.pos.z) == 1)
		game->player.pos.x += (game->camera.dir.y * game->player.mov_speed);
	if (check_next_pos(game, game->player.pos.x, game->player.pos.z
			- game->camera.dir.x * game->player.mov_speed) == 1)
		game->player.pos.z -= (game->camera.dir.x * game->player.mov_speed);
}

void	rotate_camera_with_arrow(t_game *game, int key)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = game->camera.dir.x;
	oldPlaneX = game->camera.plane.x;
	if (key == RIGHT_ARROW)
	{
		game->camera.rot_speed = game->game_time.frame_time * 3.0;
		game->camera.dir.x = game->camera.dir.x * cos(-game->camera.rot_speed)
			- game->camera.dir.y * sin(-game->camera.rot_speed);
		game->camera.dir.y = oldDirX * sin(-game->camera.rot_speed)
			+ game->camera.dir.y * cos(-game->camera.rot_speed);
		game->camera.plane.x = game->camera.plane.x
			* cos(-game->camera.rot_speed) - game->camera.plane.y
			* sin(-game->camera.rot_speed);
		game->camera.plane.y = oldPlaneX * sin(-game->camera.rot_speed)
			+ game->camera.plane.y * cos(-game->camera.rot_speed);
	}
	else
	{
		game->camera.dir.x = game->camera.dir.x * cos(game->camera.rot_speed)
			- game->camera.dir.y * sin(game->camera.rot_speed);
		game->camera.dir.y = oldDirX * sin(game->camera.rot_speed)
			+ game->camera.dir.y * cos(game->camera.rot_speed);
		game->camera.plane.x = game->camera.plane.x
			* cos(game->camera.rot_speed) - game->camera.plane.y
			* sin(game->camera.rot_speed);
		game->camera.plane.y = oldPlaneX * sin(game->camera.rot_speed)
			+ game->camera.plane.y * cos(game->camera.rot_speed);
	}
}

void	move_player(t_game *game, int key)
{
	game->player.mov_speed = game->game_time.frame_time * 5.0;
	if (key == UP)
		go_ahead(game);
	if (key == DOWN)
		go_backwards(game);
	if (key == RIGHT)
		go_right(game);
	if (key == LEFT)
		go_left(game);
	if (key == RIGHT_ARROW || key == LEFT_ARROW)
		rotate_camera_with_arrow(game, key);
}
