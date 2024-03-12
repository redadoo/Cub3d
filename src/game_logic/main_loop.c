/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:18:31 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 17:16:54 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

static void draw_quad(t_sprite *sprite, int x,int z, int lenght, int color)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (i < lenght)
	{
		while ( y < lenght)
		{
			put_pixel(sprite, x + i, z + y, color);
			y++;
		}
		y = 0;
		i++;
	}
	
}

static void draw_minimap(t_game *game)
{
	int i;
	int y;
	t_vector3_int mini_map_color;
	t_vector3_int player_mini_map_color;

	i = 0;
	y = 0;
	set_vector3_int(&mini_map_color, 192,192,192);
	set_vector3_int(&player_mini_map_color, 30,144,255);
	game->mini_map = new_img(game->mlx, matrix_width(game->map) * 6, matrix_height(game->map) * 6);
	while(game->map[y])
	{
		while(game->map[y][i])
		{
			if (game->map[y][i] == '1')
				draw_quad(&game->mini_map, i * 6, y * 6, 4,create_trgb(256,
					mini_map_color));
			i++;
		}
		i = 0;
		y++;
	}
	draw_quad(&game->mini_map, game->player.pos.x * 6, game->player.pos.z * 6, 4,create_trgb(256,
		player_mini_map_color)); 
}

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
	mlx_put_image_to_window(game->mlx, game->window.reference, game->mini_map.img,
		0, 0);
}

int	main_loop(t_game *game)
{
	renderer(game);
	safe_mlx_destroy_image(game->mlx, game->scene.img);
	safe_mlx_destroy_image(game->mlx, game->mini_map.img);
	game->scene.img = NULL;
	game->old_time = game->time;
	game->time = current_time_millis();
	game->frame_time = (game->time - game->old_time) / 1000.0;
	return (0);
}
