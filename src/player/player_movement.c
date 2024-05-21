/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:28:10 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/21 15:04:09 by edoardo          ###   ########.fr       */
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
