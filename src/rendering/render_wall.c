/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:32:06 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/28 15:08:20 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	render_wall(t_game *game)
{
	int	i;

	i = 0;
	game->world = init_img(game->mlx, game->window.size.x, game->window.size.y);
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
}

void	render_background(t_game *game, int x)
{
	int	y;

	y = -1;
	while (++y < game->raycaster.draw_start)
	{
		draw_pixel(game->world, x, y, create_trgb(256,
				game->assets.celin_color));
	}
	y = game->raycaster.draw_end - 1;
	while (++y < game->window.size.y)
	{
		draw_pixel(game->world, x, y, create_trgb(256,
				game->assets.floor_color));
	}
}

void	renderer(t_game *game)
{
	render_wall(game);
	if (game->show_minimap)
		draw_minimap(game);
	mlx_clear_window(game->mlx, game->window.reference);
	put_and_destroy_image(game, game->world.img, 0, 0);
	if (game->show_minimap)
		put_and_destroy_image(game, game->mini_map.sprite.img, WIN_WIDTH
			- game->mini_map.lenght_mini_map, 0);
}
