/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:04:18 by evocatur          #+#    #+#             */
/*   Updated: 2024/02/12 17:24:43 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	mlx_run(t_game *game)
{
	mlx_mouse_hide(game->mlx,game->window.reference);
	mlx_hook(game->window.reference, 6, (1L << 6), camera_rotation, game);
	mlx_key_hook(game->window.reference, *key_hook, game);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_hook(game->window.reference, 17, 1L << 0, *close_game, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_tgame(&game);
	if (argc != 2)
		error("wrong number of arguments", &game);
	if (check_extension(argv[1]) == 1)
		error("wrong extension for the map", &game);
	init_mlx(&game);
	load_cub3d_data(&game, argv);
	mlx_run(&game);
}
