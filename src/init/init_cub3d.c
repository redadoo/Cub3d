/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:18:11 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 17:41:26 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->window = ft_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	game->scene = init_sprite();
}

void	init_tgame(t_game *game)
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

/**
 * @brief load data in game structure(map,player)
 *
 * @param game Pointer to the game structure.
 * @param argv Command-line arguments passed to the program.
 */
void	load_cub3d_data(t_game *game, char **argv)
{
	if (!readmap(game, argv[1]))
		error("error on map content", game);
	init_player(&game->player, game->map);
	init_camera(&game->camera, game->player.dir);
	load_texture(game);
	game->time = 0;
	game->old_time = 0;
	game->frame_time = 0;
}
