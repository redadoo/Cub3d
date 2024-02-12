/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:47:56 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 15:18:28 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	init_camera(t_camera *camera, t_vector2 dir)
{
	if (dir.y == 1)
	{
		camera->plane.x = 0.66;
		camera->plane.y = 0;
	}
	else if (dir.y == -1)
	{
		camera->plane.x = -0.66;
		camera->plane.y = 0;
	}
	else if (dir.x == 1)
	{
		camera->plane.x = 0;
		camera->plane.y = 0.66;
	}
	else if (dir.x == -1)
	{
		camera->plane.x = 0;
		camera->plane.y = -0.66;
	}
	camera->dir = dir;
	camera->old_x = 0;
}

int	camera_rotation(int x, int y, t_game *game)
{
	double			old_dir_x;
	double			old_plane_x;
	double			distance;

	game->camera.rot_speed = game->frame_time * 3.0;
	old_dir_x = game->camera.dir.x;
	old_plane_x = game->camera.plane.x;
	distance = (game->camera.old_x - x) * game->camera.rot_speed;
	game->camera.old_x = x;
	game->camera.dir.x = game->camera.dir.x * cos(distance) - game->camera.dir.y
		* sin(distance);
	game->camera.dir.y = old_dir_x * sin(distance) + game->camera.dir.y
		* cos(distance);
	game->camera.plane.x = game->camera.plane.x * cos(distance)
		- game->camera.plane.y * sin(distance);
	game->camera.plane.y = old_plane_x * sin(distance) + game->camera.plane.y
		* cos(distance);
	return (EXIT_SUCCESS);
}
