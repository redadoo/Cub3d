/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:18:31 by edoardo           #+#    #+#             */
/*   Updated: 2024/03/30 16:57:27 by evocatur         ###   ########.fr       */
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
	game->scene = new_img(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	while (x < WIN_WIDTH)
	{
		set_raycaster(game, x);
		set_raycaster_dir(game);
		find_distance_tw_wall(game);
		find_wall_height(game);
		find_wall_pixel(game);
		draw_vert_line_texture(game, x);
		x++;
	}
	draw_minimap(game);
	mlx_clear_window(game->mlx, game->window.reference);
	mlx_put_image_to_window(game->mlx, game->window.reference, game->scene.img,
		0, 0);
	mlx_put_image_to_window(game->mlx, game->window.reference,
		game->mini_map.sprite.img, WIN_WIDTH - game->mini_map.lenght_mini_map, 0);
	safe_mlx_destroy_image(game->mlx, game->scene.img);
	safe_mlx_destroy_image(game->mlx, game->mini_map.sprite.img);
}

int	main_loop(t_game *game)
{
	renderer(game);
	game->game_time.old_time = game->game_time.time;
	game->game_time.time = current_time_millis();
	game->game_time.frame_time = (game->game_time.time - game->game_time.old_time) / 1000.0;
	return (0);
}
