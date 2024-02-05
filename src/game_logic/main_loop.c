/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:18:31 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/03 18:32:25 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	renderer(t_game *game)
{
	int	x;

	x = 0;
	game->img = new_img(game->mlx);
	while (x < WIN_WIDTH)
	{
		set_raycaster(game, x);
		set_raycaster_dir(game);
		find_distance_to_wall(game);
		find_wall_height(game);
		find_wall_pixel(game);
		draw_vert_line(game, x);
		x++;
	}
	mlx_clear_window(game->mlx, game->window.reference);
	mlx_put_image_to_window(game->mlx, game->window.reference, game->img.ptr, 0,
		0);
}

int	main_loop(t_game *game)
{
	renderer(game);
	mlx_destroy_image(game->mlx, game->img.ptr);
	game->img.ptr = NULL;
	return (0);
}
