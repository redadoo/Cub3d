/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:47:56 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/25 16:08:56 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	rotate_view(t_game *game, double distance)
{
	game->camera.old_dir_x = game->camera.dir.x;
	game->camera.old_plane_x = game->camera.plane.x;
	game->camera.old_x = game->camera.mouse_pos.x;
	set_vector2(&game->camera.dir, game->camera.dir.x * cos(distance)
		- game->camera.dir.y * sin(distance), game->camera.old_dir_x
		* sin(distance) + game->camera.dir.y * cos(distance));
	set_vector2(&game->camera.plane, game->camera.plane.x * cos(distance)
		- game->camera.plane.y * sin(distance), game->camera.old_plane_x
		* sin(distance) + game->camera.plane.y * cos(distance));
}

int	camera_rotation(int x, int y, t_game *game)
{
	x = -x;
	game->camera.rot_speed = game->game_time.frame_time * 3.0;
	set_vector2_int(&game->camera.mouse_pos, x, y);
	rotate_view(game, (game->camera.old_x - game->camera.mouse_pos.x)
		* game->camera.rot_speed);
	return (EXIT_SUCCESS);
}
