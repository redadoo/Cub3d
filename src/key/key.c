/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:14:22 by evocatur          #+#    #+#             */
/*   Updated: 2024/05/22 14:28:56 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	key_hook(int keycode, t_game *game)
{
	game->player.mov_speed = game->game_time.frame_time * 5.0;
	game->camera.rot_speed = game->game_time.frame_time * 3.0;
	if (keycode == EXIT)
		close_game(game);
	if (keycode == TOGGLE_MINIMAP)
		game->show_minimap = !game->show_minimap; 
	if (keycode == UP)
		go_ahead(game);
	if (keycode == DOWN)
		go_backwards(game);
	if (keycode == RIGHT)
		go_right(game);
	if (keycode == LEFT)
		go_left(game);
	if (keycode == RIGHT_ARROW)
		rotate_view(game, -game->camera.rot_speed); 
	if (keycode == LEFT_ARROW)
		rotate_view(game, game->camera.rot_speed);
	return (0);
}
