/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:28:10 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 15:04:12 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static void	move_down(t_game *game)
{
	if (check_next_pos(game, game->player.pos.x + game->camera.dir.x
			* game->player.mov_speed, game->player.pos.z) == 1)
		game->player.pos.x -= (game->camera.dir.x * game->player.mov_speed);
	if (check_next_pos(game, game->player.pos.x, game->player.pos.z
			+ game->camera.dir.y * game->player.mov_speed) == 1)
		game->player.pos.z += (game->camera.dir.y * game->player.mov_speed);
}

static void	move_up(t_game *game)
{
	if (check_next_pos(game, game->player.pos.x + game->camera.dir.x
			* game->player.mov_speed, game->player.pos.z) == 1)
		game->player.pos.x += (game->camera.dir.x * game->player.mov_speed);
	if (check_next_pos(game, game->player.pos.x, game->player.pos.z
			+ game->camera.dir.y * game->player.mov_speed) == 1)
		game->player.pos.z -= (game->camera.dir.y * game->player.mov_speed);
}

static void	move_right(t_game *game)
{
	if (check_next_pos(game, game->player.pos.x + game->camera.dir.y
			* game->player.mov_speed, game->player.pos.z) == 1)
		game->player.pos.x += (game->camera.dir.y * game->player.mov_speed);
	if (check_next_pos(game, game->player.pos.x, game->player.pos.z
			+ game->camera.dir.x * game->player.mov_speed) == 1)
		game->player.pos.z += (game->camera.dir.x * game->player.mov_speed);
}

static void	move_left(t_game *game)
{
	if (check_next_pos(game, game->player.pos.x - game->camera.dir.y
			* game->player.mov_speed, game->player.pos.z) == 1)
		game->player.pos.x -= (game->camera.dir.y * game->player.mov_speed);
	if (check_next_pos(game, game->player.pos.x, game->player.pos.z
			- game->camera.dir.x * game->player.mov_speed) == 1)
		game->player.pos.z -= (game->camera.dir.x * game->player.mov_speed);
}

void	move_player(t_game *game, int key)
{
	game->player.mov_speed = game->frame_time * 5.0;
	if (key == UP)
		move_up(game);
	if (key == DOWN)
		move_down(game);
	if (key == RIGHT)
		move_right(game);
	if (key == LEFT)
		move_left(game);
}
