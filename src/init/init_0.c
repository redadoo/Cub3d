/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:18:11 by edoardo           #+#    #+#             */
/*   Updated: 2024/05/28 15:08:20 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	init_mini_map(t_game *game)
{
	int	offset;

	offset = 10;
	game->mini_map.lenght_mini_map = matrix_width(game->map) * offset;
	set_vector3_int(&game->mini_map.title_color, 192, 192, 192);
	set_vector3_int(&game->mini_map.player_color, 30, 144, 255);
	game->mini_map.offset_draw = 9;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->window = ft_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	game->world = get_empty_sprite();
	game->mini_map.sprite = get_empty_sprite();
}

void	set_null(t_game *game)
{
	game->mlx = NULL;
	game->assets.e_wall.path = NULL;
	game->assets.w_wall.path = NULL;
	game->assets.s_wall.path = NULL;
	game->assets.n_wall.path = NULL;
	game->assets.e_wall.img = NULL;
	game->assets.w_wall.img = NULL;
	game->assets.s_wall.img = NULL;
	game->assets.n_wall.img = NULL;
	game->map = NULL;
	game->window.reference = NULL;
}

void	load_cub3d_data(t_game *game, char **argv)
{
	if (!readmap(game, argv[1]))
		error("error on map content", game);
	init_player(&game->player, game->map);
	init_camera(&game->camera, game->player.dir);
	load_sprites(game);
	init_mini_map(game);
	game->game_time.frame_time = 0;
	game->game_time.old_time = 0;
	game->game_time.time = 0;
	game->show_minimap = true;
}

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
	set_vector2(&camera->dir, -dir.x, -dir.y);
	camera->old_x = 0;
}
