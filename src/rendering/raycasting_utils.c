/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:09:26 by edoardo           #+#    #+#             */
/*   Updated: 2024/04/13 14:09:48 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/cub3d.h"

void	wall_hit(t_game *game)
{
	if (!game->raycaster.side)
		game->raycaster.wall_x = (int)game->player.pos.z
			+ game->raycaster.perp_wall_dist * game->raycaster.ray_dir.y;
	else
		game->raycaster.wall_x = (int)game->player.pos.x
			+ game->raycaster.perp_wall_dist * game->raycaster.ray_dir.x;
	game->raycaster.wall_x -= floor(game->raycaster.wall_x);
	game->raycaster.tex.x = (int)(game->raycaster.wall_x
			* (double)TEXTURE_WIDTH);
	if (game->raycaster.side == 0 && game->raycaster.ray_dir.x > 0)
		game->raycaster.tex.x = TEXTURE_WIDTH - game->raycaster.tex.x - 1;
	if (game->raycaster.side == 1 && game->raycaster.ray_dir.y < 0)
		game->raycaster.tex.x = TEXTURE_WIDTH - game->raycaster.tex.x - 1;
	game->raycaster.step = 1.0 * TEXTURE_HEIGHT / game->raycaster.line_height;
	game->raycaster.tex_pos = (game->raycaster.draw_start - 100 - WIN_HEIGHT / 2
			+ game->raycaster.line_height / 2) * game->raycaster.step;
}
