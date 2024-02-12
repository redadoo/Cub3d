/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:18:31 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 12:53:27 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static int64_t	current_time_millis(void)
{
	struct timeval	time;
	int64_t			s1;
	int64_t			s2;

	gettimeofday(&time, NULL);
	s1 = (int64_t)(time.tv_sec) * 1000;
	s2 = (time.tv_usec / 1000);
	return (s1 + s2);
}

void	renderer(t_game *game)
{
	int	x;

	x = 0;
	game->scene = new_img(game->mlx);
	while (x < WIN_WIDTH)
	{
		set_raycaster(game, x);
		set_raycaster_dir(game);
		find_distance_to_wall(game);
		find_wall_height(game);
		find_wall_pixel(game);
		draw_vert_line_texture(game, x);
		x++;
	}
	mlx_clear_window(game->mlx, game->window.reference);
	mlx_put_image_to_window(game->mlx, game->window.reference, game->scene.img,
		0, 0);
}

int	main_loop(t_game *game)
{
	t_vector2_int	mouse_pos;

	renderer(game);
	safe_mlx_destroy_image(game->mlx, game->scene.img);
	game->scene.img = NULL;
	game->old_time = game->time;
	game->time = current_time_millis();
	game->frame_time = (game->time - game->old_time) / 1000.0;
	return (0);
}
