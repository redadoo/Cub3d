/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:15:32 by edoardo           #+#    #+#             */
/*   Updated: 2024/02/12 17:40:46 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

int	close_game(t_game *game)
{
	safe_mlx_destroy_image(game->mlx, game->assets.e_wall.img);
	safe_mlx_destroy_image(game->mlx, game->assets.n_wall.img);
	safe_mlx_destroy_image(game->mlx, game->assets.w_wall.img);
	safe_mlx_destroy_image(game->mlx, game->assets.s_wall.img);
	safe_free(game->assets.e_wall.path);
	safe_free(game->assets.n_wall.path);
	safe_free(game->assets.w_wall.path);
	safe_free(game->assets.s_wall.path);
	free_matrix(game->map);
	safe_mlx_clear_window(game->mlx, game->window.reference);
	safe_mlx_destroy_window(game->mlx, game->window.reference);
	safe_mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
