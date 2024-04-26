/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:47:56 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/26 13:59:24 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	init_camera(t_camera *camera, t_vector2 dir)
{
	if (dir.y == 1)
		set_vector2(&camera->plane, 0.66, 0);
	else if (dir.y == -1)
		set_vector2(&camera->plane, -0.66, 0);
	else if (dir.x == 1)
		set_vector2(&camera->plane, 0, -0.66);
	else if (dir.x == -1)
		set_vector2(&camera->plane, 0, 0.66);
	camera->dir = dir;
	camera->old_x = 0;
}

int	camera_rotation(int x, int y, t_game *game)
{
	set_vector2_int(&game->camera.mouse_pos, x, y);
	game->camera.rot_speed = game->game_time.frame_time * 3.0;
	game->camera.old_dir_x = game->camera.dir.x;
	game->camera.old_plane_x = game->camera.plane.x;
	game->camera.distance = (game->camera.old_x - game->camera.mouse_pos.x)
		* game->camera.rot_speed;
	game->camera.old_x = game->camera.mouse_pos.x;
	set_vector2(&game->camera.dir, game->camera.dir.x
		* cos(game->camera.distance) - game->camera.dir.y
		* sin(game->camera.distance), game->camera.old_dir_x
		* sin(game->camera.distance) + game->camera.dir.y
		* cos(game->camera.distance));
	set_vector2(&game->camera.plane, game->camera.plane.x
		* cos(game->camera.distance) - game->camera.plane.y
		* sin(game->camera.distance), game->camera.old_plane_x
		* sin(game->camera.distance) + game->camera.plane.y
		* cos(game->camera.distance));
	return (EXIT_SUCCESS);
}
