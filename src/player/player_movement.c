/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:28:10 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/28 13:52:50 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	front_movement(t_game *game, bool is_ahead)
{
	if (is_ahead)
	{
		if (check_next_pos(game, game->player.pos.x + game->camera.dir.x
				* game->player.mov_speed, game->player.pos.z) == 1)
			game->player.pos.x += (game->camera.dir.x * game->player.mov_speed);
		if (check_next_pos(game, game->player.pos.x, game->player.pos.z
				+ game->camera.dir.y * game->player.mov_speed) == 1)
			game->player.pos.z += (game->camera.dir.y * game->player.mov_speed);
	}
	else
	{
		if (check_next_pos(game, game->player.pos.x - game->camera.dir.x
				* game->player.mov_speed, game->player.pos.z) == 1)
			game->player.pos.x -= (game->camera.dir.x * game->player.mov_speed);
		if (check_next_pos(game, game->player.pos.x, game->player.pos.z
				- game->camera.dir.y * game->player.mov_speed) == 1)
			game->player.pos.z -= (game->camera.dir.y * game->player.mov_speed);
	}
}

void	lateral_movement(t_game *game, bool is_left)
{
	if (is_left)
	{
		if (check_next_pos(game, game->player.pos.x + game->camera.dir.y
				* game->player.mov_speed, game->player.pos.z) == 1)
			game->player.pos.x += (game->camera.dir.y * game->player.mov_speed);
		if (check_next_pos(game, game->player.pos.x, game->player.pos.z
				- game->camera.dir.x * game->player.mov_speed) == 1)
			game->player.pos.z -= (game->camera.dir.x * game->player.mov_speed);
	}
	else
	{
		if (check_next_pos(game, game->player.pos.x - game->camera.dir.y
				* game->player.mov_speed, game->player.pos.z) == 1)
			game->player.pos.x -= (game->camera.dir.y * game->player.mov_speed);
		if (check_next_pos(game, game->player.pos.x, game->player.pos.z
				+ game->camera.dir.x * game->player.mov_speed) == 1)
			game->player.pos.z += (game->camera.dir.x * game->player.mov_speed);
	}
}
