/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:04:18 by evocatur          #+#    #+#             */
/*   Updated: 2024/02/03 18:02:10 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

static int	init_game(t_game *game, char **argv)
{
	game->mlx = mlx_init();
	game->map = readmap(argv[1]);
	init_player(&game->player, game->map.matrix);
	init_camera(&game->camera);
	game->img = init_img();
	game->window = ft_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	return (0);
}

static void	mlx_run(t_game *game)
{
	mlx_mouse_hide(game->mlx, game->window.reference);
	mlx_key_hook(game->window.reference, *key_hook, &game);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_hook(game->window.reference, 17, 0, *close_game, &game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || check_extension(argv[1]) == 1)
		close_game(&game);
	if (init_game(&game, argv) != 0)
		close_game(&game);
	mlx_run(&game);
}
