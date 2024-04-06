/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:47:56 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/06 14:48:48 by edoardo          ###   ########.fr       */
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

/* int	manage_mouse_scroll(int x, t_game *game)
{
	if (x < 10 || x > WIN_WIDTH - 10)
		game->camera.mouse_on_edge = true;
	else
		game->camera.mouse_on_edge = false;
	if (game->camera.mouse_on_edge == true)
		mlx_mouse_move(game->mlx, game->window.reference, x, 100);
	return (x);
} */
int	camera_rotation(int x, int y, t_game *game)
{
	(void)y;
	game->camera.rot_speed = game->game_time.frame_time * 3.0;
	game->camera.old_dir_x = game->camera.dir.x;
	game->camera.old_plane_x = game->camera.plane.x;
	game->camera.distance = (game->camera.old_x - x) * game->camera.rot_speed;
	game->camera.old_x = x;
	game->camera.dir.x = game->camera.dir.x * cos(game->camera.distance)
		- game->camera.dir.y * sin(game->camera.distance);
	game->camera.dir.y = game->camera.old_dir_x * sin(game->camera.distance)
		+ game->camera.dir.y * cos(game->camera.distance);
	game->camera.plane.x = game->camera.plane.x * cos(game->camera.distance)
		- game->camera.plane.y * sin(game->camera.distance);
	game->camera.plane.y = game->camera.old_plane_x * sin(game->camera.distance)
		+ game->camera.plane.y * cos(game->camera.distance);
	return (EXIT_SUCCESS);
}
