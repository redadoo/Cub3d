/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:18:31 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/13 13:55:55 by edoardo          ###   ########.fr       */
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
	int	i;

	i = 0;
	game->scene = init_img(game->mlx, game->window.size.x, game->window.size.y);
	while (i < game->window.size.x)
	{
		set_raycaster(game, i);
		set_raycaster_dir(game);
		start_dda(game);
		ray_distance(game);
		pixel_to_fill(game);
		wall_hit(game);
		draw_screen(game, i);
		i++;
	}
	draw_minimap(game);
	mlx_clear_window(game->mlx, game->window.reference);
	mlx_put_image_to_window(game->mlx, game->window.reference, game->scene.img,
		0, 0);
	mlx_put_image_to_window(game->mlx, game->window.reference,
		game->mini_map.sprite.img,
		WIN_WIDTH - game->mini_map.lenght_mini_map, 0);
	safe_mlx_destroy_image(game->mlx, game->scene.img);
	safe_mlx_destroy_image(game->mlx, game->mini_map.sprite.img);
}

void	manage_time(t_game *game)
{
	game->game_time.old_time = game->game_time.time;
	game->game_time.time = current_time_millis();
	game->game_time.frame_time = (
			game->game_time.time - game->game_time.old_time) / 1000.0;
}

int	main_loop(t_game *game)
{
	renderer(game);
	manage_time(game);
	return (0);
}
