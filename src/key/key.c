/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:14:22 by evocatur          #+#    #+#             */
/*   Updated: 2024/05/28 13:54:11 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	key_hook(int keycode, t_game *game)
{
	game->player.mov_speed = game->game_time.frame_time * 5.0;
	game->camera.rot_speed = game->game_time.frame_time * 3.0;
	if (keycode == EXIT)
		close_game(game);
	if (keycode == F1)
		game->show_minimap = !game->show_minimap;
	if (keycode == UP || keycode == DOWN)
		front_movement(game, keycode == UP);
	if (keycode == RIGHT || keycode == LEFT)
		lateral_movement(game, keycode == LEFT);
	if (keycode == RIGHT_ARROW)
		rotate_view(game, game->camera.rot_speed);
	if (keycode == LEFT_ARROW)
		rotate_view(game, -game->camera.rot_speed);
	return (0);
}
